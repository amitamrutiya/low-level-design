# Library Management System - UML Design Documentation

## Overview
This document outlines the detailed design of a Library Management System following SOLID principles, focusing on the Class Diagram representation that showcases the complete system architecture. The design emphasizes modularity, extensibility, and maintainability while ensuring all library management functionalities are properly encapsulated.

## Class Diagram Components

### Interfaces
1. **ILibraryItem**
   - Core interface for all library items
   - Defines common operations like status checks and availability
   - Enables polymorphic handling of different item types
   
2. **INotificationService**
   - Interface for notification implementations
   - Allows multiple notification channels (email, SMS, push)
   - Follows Interface Segregation Principle
   
3. **IPaymentProcessor**
   - Interface for payment processing
   - Supports different payment methods
   - Handles both payments and refunds

## System Components

### 1. Users
- **LibraryMember**
  - Regular members who can borrow and return books
  - Attributes: memberId, name, email, phoneNumber, membershipStatus
  - Can reserve books, view their borrowing history, and pay fines

- **Librarian**
  - Staff members who manage library operations
  - Can add/remove books, manage members, and handle transactions
  - Has additional privileges for system administration

- **Admin**
  - Super users with full system access
  - Can manage librarians, generate reports, and configure system settings

### 2. Library Items
- **Book**
  - Physical books with ISBN, title, author(s), publisher
  - Tracks availability status and location
  - Contains metadata like genre, publication date

- **EBook**
  - Digital books with download/streaming capabilities
  - Includes DRM management and concurrent user limits

- **Magazine/Journal**
  - Periodicals with volume/issue numbers
  - May have different borrowing rules

- **AudioVisual Material**
  - DVDs, CDs, and other media
  - Special handling for different formats

### 3. Core Operations
- **Catalog Management**
  - Search and browse functionality
  - Category and tag management
  - ISBN lookup and validation

- **Circulation System**
  - Handles check-out/check-in
  - Manages reservations and waiting lists
  - Late fee calculation
  - Return date tracking

- **Inventory Management**
  - Stock tracking
  - Purchase orders
  - Damage/loss handling

### 4. Supporting Systems
- **Notification System**
  - Due date reminders
  - Reservation notifications
  - Fine notifications
  - System announcements

- **Fine Management**
  - Calculate fines
  - Process payments
  - Generate receipts
  - Handle fine disputes

- **Reporting System**
  - Usage statistics
  - Inventory reports
  - Financial reports
  - Member activity reports

## SOLID Principles Implementation

### 1. Single Responsibility Principle (SRP)
- **CatalogManager**: Handles only catalog-related operations
- **NotificationManager**: Focuses solely on notification delivery
- **Fine**: Manages only fine-related calculations and status
- **BorrowRecord**: Maintains borrowing history and due dates
- Each class has a single, well-defined purpose

### 2. Open/Closed Principle (OCP)
- **ILibraryItem**: New types can be added by implementing this interface
- **INotificationService**: New notification methods can be added without changing existing code
- **IPaymentProcessor**: New payment methods can be integrated easily
- Enums (ItemStatus, MembershipStatus) can be extended for new states

### 3. Liskov Substitution Principle (LSP)
- All library items (Book, EBook, Magazine, AudioVisual) can be used wherever ILibraryItem is expected
- User hierarchy (LibraryMember, Librarian, Admin) maintains consistent base behavior
- BorrowRecord works with any type of ILibraryItem
- No violation of parent class contracts in child classes

### 4. Interface Segregation Principle (ISP)
- ILibraryItem: Contains only essential methods for library items
- INotificationService: Focused only on notification functionality
- IPaymentProcessor: Dedicated to payment operations
- No class is forced to implement unnecessary methods

### 5. Dependency Inversion Principle (DIP)
- NotificationManager depends on INotificationService interface, not concrete implementations
- CatalogManager works with ILibraryItem interface
- High-level modules (LibraryMember, Librarian) depend on abstractions
- System configuration uses interfaces for external services

## Class Relationships and Associations

### User Hierarchy
- Abstract `User` class with common attributes (userId, name, email)
- Specialized classes:
  - `LibraryMember`: Regular library users with borrowing privileges
  - `Librarian`: Staff members with administrative capabilities
  - `Admin`: System administrators with full control

### Item Hierarchy
- `ILibraryItem` interface implemented by:
  - `Book`: Traditional physical books
  - `EBook`: Digital books with download/streaming
  - `Magazine`: Periodicals with volume/issue tracking
  - `AudioVisual`: Media items with format-specific attributes

### Supporting Classes
1. **BorrowRecord**
   - Tracks individual borrowing transactions
   - Links members with items
   - Manages due dates and return status

2. **Fine**
   - Handles monetary penalties
   - Tracks payment status
   - Associates with members and borrow records

3. **Reservation**
   - Manages item reservations
   - Implements queuing system
   - Handles notification triggers

4. **CatalogManager**
   - Central catalog management
   - Search and retrieval functionality
   - Inventory tracking

### Enumerations
1. **ItemStatus**
   - AVAILABLE: Ready for borrowing
   - BORROWED: Currently checked out
   - RESERVED: Held for a member
   - MAINTENANCE: Under repair/review
   - LOST: Missing from inventory

2. **MembershipStatus**
   - ACTIVE: Full privileges
   - SUSPENDED: Temporary block
   - EXPIRED: Needs renewal
   - BLACKLISTED: Permanently blocked

3. **FineStatus**
   - PENDING: Unpaid
   - PAID: Cleared
   - DISPUTED: Under review
   - WAIVED: Forgiven by staff

4. **ReservationStatus**
   - PENDING: Awaiting item
   - FULFILLED: Item available
   - CANCELLED: User cancelled
   - EXPIRED: Time limit passed

## UML Diagrams Included

1. **Class Diagram**
   - Shows the static structure of the system
   - Displays relationships between classes
   - Includes attributes and methods

2. **Use Case Diagram**
   - Illustrates system functionality from user perspective
   - Shows different actor interactions

3. **Sequence Diagram**
   - Demonstrates the book borrowing process
   - Shows the return process
   - Illustrates fine payment flow

4. **Activity Diagram**
   - Shows the workflow of book procurement
   - Illustrates the member registration process

5. **State Diagram**
   - Shows the lifecycle of a book
   - Illustrates the states of a library member

## System Interfaces

### 1. User Interfaces
- Web-based admin portal
- Mobile app for members
- Self-service kiosk interface

### 2. External Interfaces
- Payment gateway integration
- Email/SMS service integration
- ISBN database integration
- Library network integration

## Security Considerations

1. **Authentication**
   - Role-based access control
   - Multi-factor authentication for staff
   - Session management

2. **Data Protection**
   - Encryption of sensitive data
   - Secure password storage
   - Regular backups

3. **Audit Trail**
   - Logging of all critical operations
   - User activity tracking
   - System access logs

## Future Extensibility

1. **Integration Capabilities**
   - API for third-party integrations
   - Support for additional item types
   - New payment methods

2. **Scalability**
   - Support for multiple branches
   - Cloud deployment options
   - Performance optimization

## Testing Strategy

1. **Unit Testing**
   - Individual component testing
   - Mock object usage
   - Automated test cases

2. **Integration Testing**
   - Component interaction testing
   - External service integration testing

3. **System Testing**
   - End-to-end workflow testing
   - Performance testing
   - Security testing
