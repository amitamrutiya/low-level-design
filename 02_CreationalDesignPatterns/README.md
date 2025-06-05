# Creational Design Patterns

Creational Design Patterns provide various object creation mechanisms that increase flexibility and reuse of existing code. They abstract the instantiation process, making a system independent of how its objects are created, composed, and represented.

## Overview of Creational Design Patterns

This directory contains implementations of five fundamental creational design patterns:

1. **Singleton Pattern**: Ensures a class has only one instance and provides a global point of access to it.

2. **Factory Method Pattern**: Creates objects without exposing the instantiation logic to the client and refers to the newly created object through a common interface.

3. **Abstract Factory Pattern**: Provides an interface for creating families of related or dependent objects without specifying their concrete classes.

4. **Builder Pattern**: Separates the construction of a complex object from its representation, allowing the same construction process to create various representations.

5. **Prototype Pattern**: Creates new objects by cloning an existing object, known as the prototype, instead of creating new instances from scratch.

## Key Concepts

- **Object Creation**: These patterns deal with object creation mechanisms and try to create objects in a manner suitable to the situation.
  
- **Flexibility**: They provide flexibility in deciding which objects need to be created for a given use case.
  
- **Decoupling**: They promote loose coupling by eliminating the need to bind application-specific classes into the code.

## Common Use Cases

1. **Singleton Pattern**:
   - Database connections
   - Configuration settings
   - Logger instances

2. **Factory Method**:
   - UI component creation
   - Document generators
   - Data access object creation

3. **Abstract Factory**:
   - Cross-platform UI toolkits
   - Multiple database support
   - Different payment gateway implementations

4. **Builder Pattern**:
   - Complex object construction
   - Object with many optional parameters
   - Immutable objects with multiple fields

5. **Prototype Pattern**:
   - Object cloning
   - Template objects
   - Avoiding expensive object creation

## Benefits

1. **Encapsulation**: Hide creation logic from client code
2. **Flexibility**: Easy to change implementations
3. **Reusability**: Promote code reuse
4. **Loose Coupling**: Reduce dependencies between components
5. **Single Responsibility**: Separate object creation from business logic

## Directory Structure
```
02_CreationalDesignPatterns/
├── README.md (this file)
├── 01_SingletonDesignPattern/
├── 02_FactoryMethod/
├── 03_AbstractFactory/
├── 04_BuilderPattern/
└── 05_PrototypePattern/
```

Each pattern directory contains:
- README.md: Detailed explanation of the pattern
- Main.java: Good implementation example
- badCode.java: Example of code that violates the pattern principles
