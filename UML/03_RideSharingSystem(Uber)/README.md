# Ride Sharing System Design (Like Uber)

This document explains the design of a ride-sharing system similar to Uber, following SOLID principles and incorporating various design patterns.

## Core Components

### 1. User Management
- **User (Abstract Class)**
  - Base class for both Passenger and Driver
  - Handles common user attributes and operations
  - Following SRP by separating user management from ride management

- **Passenger**
  - Manages passenger-specific operations like booking rides
  - Can save locations and manage payment methods
  - Can rate drivers after ride completion

- **Driver**
  - Handles driver-specific operations
  - Manages availability status and current location
  - Can accept/reject ride requests
  - Can rate passengers after ride completion

### 2. Location Management
- **Location**
  - Represents geographical coordinates
  - Provides distance calculation functionality
  - Used for both pickup and drop-off points

- **SavedLocation**
  - Allows passengers to save frequently used locations
  - Associates a name with a location for easy reference

### 3. Ride Management
- **Ride**
  - Central entity managing ride information
  - Links passengers, drivers, and locations
  - Handles ride status and payment information
  - Uses Strategy pattern for pricing

- **RideType & RideStatus (Enums)**
  - RideType: Different service levels (ECONOMY, PREMIUM, POOL)
  - RideStatus: Various states a ride can be in

### 4. Payment System
- **PaymentInfo**
  - Handles payment processing and refunds
  - Supports multiple payment methods
  - Follows SRP by separating payment concerns

- **PaymentType (Enum)**
  - Supported payment methods (CREDIT_CARD, DEBIT_CARD, DIGITAL_WALLET, CASH)

### 5. Rating System
- **Rating**
  - Bi-directional rating system
  - Stores ratings and comments
  - Timestamps for tracking purposes

### 6. Pricing System
- **PricingStrategy (Interface)**
  - Defines contract for pricing calculations
  - Follows Open/Closed Principle for easy extension

- **Implementations**
  - DynamicPricing: Implements surge pricing
  - FixedPricing: Standard rate calculation

### 7. Matching System
- **RideMatchingSystem**
  - Matches passengers with nearby drivers
  - Considers factors like distance and ratings
  - Optimizes for efficient matching

### 8. Notification System
- **NotificationService (Interface)**
  - Defines contract for sending notifications
  - Follows Interface Segregation Principle

- **Implementations**
  - EmailNotification
  - SMSNotification
  - PushNotification

## SOLID Principles Implementation

1. **Single Responsibility Principle (SRP)**
   - Each class has a single, well-defined responsibility
   - Separate classes for User, Ride, Payment, and Notification management

2. **Open/Closed Principle (OCP)**
   - PricingStrategy interface allows adding new pricing models without modifying existing code
   - NotificationService interface enables adding new notification methods

3. **Liskov Substitution Principle (LSP)**
   - Passenger and Driver properly extend User class
   - All pricing strategies can be used interchangeably

4. **Interface Segregation Principle (ISP)**
   - Separate interfaces for different functionalities
   - NotificationService interface is focused and minimal

5. **Dependency Inversion Principle (DIP)**
   - High-level modules depend on abstractions
   - Use of interfaces for Pricing and Notification systems

## Design Patterns Used

1. **Strategy Pattern**
   - Used in PricingStrategy for different pricing calculations
   - Allows runtime switching between pricing strategies

2. **Observer Pattern**
   - Implemented in NotificationService
   - Allows different types of notifications to be sent based on events

3. **Factory Method**
   - Can be implemented for creating different types of rides
   - Ensures proper initialization of ride objects

## Relationships

- A User can be either a Passenger or Driver (Inheritance)
- A Passenger can have multiple SavedLocations (One-to-Many)
- A Ride involves one Passenger and one Driver (One-to-One)
- A Ride has exactly two Locations (pickup and dropoff)
- Users can have multiple Ratings (Many-to-Many)
- Each Ride uses one PricingStrategy

## Extensibility

The system is designed to be easily extensible:
- New ride types can be added by extending RideType
- New payment methods can be added to PaymentType
- New pricing strategies can be implemented via PricingStrategy interface
- Additional notification methods can be added by implementing NotificationService
