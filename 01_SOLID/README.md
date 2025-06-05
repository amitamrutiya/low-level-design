# SOLID Principles

SOLID is a set of five object-oriented design principles intended to make software designs more maintainable, flexible, and easy to understand.

## Quick Reference

### 1. Single Responsibility Principle (SRP)
**Simple Definition**: A class should do one thing only.

**Real-World Example**: Think of a restaurant worker. Instead of having one person do everything (cooking, serving, cleaning), each person has a specific role:
- Chef → Cooking
- Waiter → Serving
- Cleaner → Cleaning

### 2. Open-Closed Principle (OCP)
**Simple Definition**: Code should be open for extension but closed for modification.

**Real-World Example**: Think of a smartphone and its cases:
- The phone design is fixed (closed for modification)
- But you can add new cases or accessories (open for extension)
- You don't need to change the phone to add a new case

### 3. Liskov Substitution Principle (LSP)
**Simple Definition**: If Class B is a subclass of Class A, then you should be able to use B instead of A without breaking the code.

**Real-World Example**: Think of different types of birds:
- A regular bird can fly and walk
- A penguin can walk but can't fly
- Therefore, penguin shouldn't inherit from a flying bird class

### 4. Interface Segregation Principle (ISP)
**Simple Definition**: Don't force classes to implement methods they don't need.

**Real-World Example**: Think of a restaurant menu:
- Instead of one large menu with everything
- Separate menus for breakfast, lunch, dinner, and desserts
- Customers only look at what they need

### 5. Dependency Inversion Principle (DIP)
**Simple Definition**: High-level modules should depend on abstractions, not concrete implementations.

**Real-World Example**: Think of a TV remote:
- The remote (high-level) works with any TV brand (low-level)
- Because both follow a standard interface (abstraction)
- You can change your TV without buying a new remote

## Benefits of SOLID

1. **Maintainability**: Easier to maintain and modify code
2. **Flexibility**: Easier to extend and add new features
3. **Reusability**: More reusable components
4. **Testability**: Easier to test code
5. **Readability**: Clearer code organization and structure

## Common Mistakes to Avoid

1. **Over-Engineering**: Don't apply SOLID principles when they're not needed
2. **Premature Abstraction**: Don't create interfaces for everything
3. **Rigid Following**: Use principles as guidelines, not strict rules
4. **Ignoring Context**: Consider project size and requirements

## When to Use Each Principle

### Use SRP When:
- A class has multiple unrelated methods
- Changes to one feature affect others
- The class is getting too large

### Use OCP When:
- You expect frequent feature additions
- You want to minimize changes to existing code
- You need plugin-like architecture

### Use LSP When:
- Creating class hierarchies
- Working with inheritance
- Designing base classes

### Use ISP When:
- Creating large interfaces
- Classes implement unnecessary methods
- Different clients need different methods

### Use DIP When:
- Managing dependencies between modules
- Need to switch implementations easily
- Want to improve testability

## Directory Structure
```
01_SOLID/
├── README.md (this file)
├── 01_SingleResponsibilityPrinciple (SRP)/
├── 02_OpenClosedPrinciple (OCP)/
├── 03_LiskovSubstitutionPrinciple (LSP)/
├── 04_InterfaceSegregationPrinciple (ISP)/
└── 05_DependencyInversionPrinciple (DIP)/
```

Each subdirectory contains:
- `README.md`: Detailed explanation of the principle
- `Main.java`: Good implementation example
- `badCode.java`: Example of code that violates the principle

## Getting Started
1. Start with SRP as it's the most fundamental
2. Move through principles in order
3. Study both good and bad examples
4. Try to identify violations in your own code
5. Practice refactoring using these principles
