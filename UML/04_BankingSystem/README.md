# Banking System Design Documentation

This document explains the detailed UML class diagram for a banking system designed following SOLID principles.

## Core Components

### 1. Account Management
- **IAccount**: Interface defining core account operations
- **Account**: Abstract base class implementing common account functionality
- **Account Types**:
  - `SavingsAccount`: Interest-bearing account with minimum balance
  - `CheckingAccount`: Regular transactional account with overdraft facility
  - `FixedDepositAccount`: Time-deposit account with maturity period

### 2. Customer Management
- **Customer**: Represents bank customers with personal details
- **Address**: Value object for storing address information
- **Bank**: Central entity managing branches and customers
- **Branch**: Represents bank branches with staff

### 3. Transaction System
- **ITransaction**: Interface for different transaction types
- **Transaction Types**:
  - `TransferTransaction`: Handles money transfer between accounts
  - `DepositTransaction`: Manages deposits into accounts
  - `WithdrawalTransaction`: Processes withdrawals from accounts
- **TransactionType**: Enum defining transaction categories
- **TransactionStatus**: Enum tracking transaction states

### 4. Notification System
- **INotification**: Interface for notification services
- **EmailNotification**: Email-based notification implementation
- **SMSNotification**: SMS-based notification implementation

### 5. Employee Management
- **Employee**: Represents bank staff members
- **Branch Management**: Employees are associated with branches

## SOLID Principles Implementation

### 1. Single Responsibility Principle (SRP)
- Each class has one specific responsibility:
  - `Account` handles account-specific operations
  - `Transaction` manages transaction logic
  - `Notification` handles customer communications
  - `Employee` manages staff-related functions

### 2. Open/Closed Principle (OCP)
- Account hierarchy is extensible for new account types
- Transaction system can be extended with new transaction types
- Notification system can add new notification methods

### 3. Liskov Substitution Principle (LSP)
- All account types (Savings, Checking, Fixed Deposit) can be used wherever an `IAccount` is expected
- All transaction types properly implement the `ITransaction` interface
- Notification implementations are interchangeable through `INotification`

### 4. Interface Segregation Principle (ISP)
- `IAccount` interface includes only essential account operations
- `ITransaction` defines specific transaction behavior
- `INotification` focuses solely on notification capabilities

### 5. Dependency Inversion Principle (DIP)
- High-level modules depend on abstractions:
  - Business logic depends on `IAccount` instead of concrete account classes
  - Transaction processing depends on `ITransaction`
  - Notification system depends on `INotification`

## Key Features

1. **Account Management**
   - Multiple account types support
   - Balance tracking
   - Interest calculation
   - Transaction history

2. **Transaction Processing**
   - Secure money transfers
   - Deposit/withdrawal operations
   - Transaction status tracking
   - Transaction history maintenance

3. **Customer Service**
   - Customer profile management
   - Multiple account ownership
   - Address management
   - Notification preferences

4. **Branch Operations**
   - Branch management
   - Employee assignment
   - Location tracking
   - Staff hierarchy

5. **Security & Notifications**
   - Transaction validation
   - Multi-channel notifications
   - Status updates
   - Alert system

## Relationships

1. **Customer-Account**: One-to-many relationship
2. **Bank-Branch**: One-to-many relationship
3. **Branch-Employee**: One-to-many relationship
4. **Account-Transaction**: Many-to-many relationship
5. **Customer-Bank**: Many-to-one relationship

## Extensions & Flexibility

The system is designed to be extensible for:
1. New account types
2. Additional transaction types
3. More notification channels
4. Enhanced security features
5. Additional customer services
