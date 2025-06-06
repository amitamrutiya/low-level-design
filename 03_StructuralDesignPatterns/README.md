# Structural Design Patterns

Structural Design Patterns are concerned with how classes and objects are composed to form larger structures. They help ensure that when parts of a system change, the entire system doesn't need to change.

## Overview of Structural Patterns

This directory contains implementations of seven fundamental structural design patterns:

### 1. Adapter Pattern
- **Purpose**: Converts interface of one class into another interface clients expect
- **Use Case**: Legacy system integration, third-party library compatibility
- **Example**: Card reader adapting SD card to USB interface

### 2. Bridge Pattern
- **Purpose**: Separates abstraction from implementation so both can vary independently
- **Use Case**: When you need to extend a class in several independent dimensions
- **Example**: Different types of remote controls for different types of devices

### 3. Composite Pattern
- **Purpose**: Composes objects into tree structures to represent part-whole hierarchies
- **Use Case**: When you need to treat individual objects and compositions uniformly
- **Example**: File system with files and directories

### 4. Decorator Pattern
- **Purpose**: Adds new responsibilities to objects dynamically
- **Use Case**: When you need to extend functionality at runtime
- **Example**: Adding toppings to a pizza, adding features to a car

### 5. Facade Pattern
- **Purpose**: Provides unified interface to a set of interfaces in a subsystem
- **Use Case**: Simplifying complex systems, providing entry point to subsystem
- **Example**: Home theater system with single button operation

### 6. Flyweight Pattern
- **Purpose**: Minimizes memory usage by sharing data across similar objects
- **Use Case**: When system needs to support large numbers of similar objects
- **Example**: Character formatting in a text editor

### 7. Proxy Pattern
- **Purpose**: Provides a surrogate for another object to control access
- **Use Case**: Lazy loading, access control, logging, caching
- **Example**: Virtual proxy for loading heavy images

## Key Concepts

- **Object Composition**: Combining objects or classes into more complex structures
- **Relationship Management**: Managing relationships between components
- **Interface Adaptation**: Making incompatible interfaces work together
- **Resource Optimization**: Efficient handling of system resources

## Common Use Cases

1. **System Integration**
   - Adapting interfaces (Adapter)
   - Simplifying complex subsystems (Facade)
   - Controlling access to resources (Proxy)

2. **Performance Optimization**
   - Sharing common state (Flyweight)
   - Lazy loading of resources (Proxy)
   - Efficient object composition (Composite)

3. **Flexibility and Extension**
   - Dynamic behavior addition (Decorator)
   - Implementation separation (Bridge)
   - Uniform object treatment (Composite)

## Benefits

1. **Maintainability**: 
   - Clean separation of concerns
   - Easier system evolution
   - Better code organization

2. **Reusability**:
   - Promotes component reuse
   - Reduces code duplication
   - Standardizes integration patterns

3. **Flexibility**:
   - Runtime behavior modification
   - Easy system extension
   - Independent variation of components

## Directory Structure
```
03_StructuralDesignPatterns/
├── README.md (this file)
├── 01_AdapterPattern/
├── 02_BridgePattern/
├── 03_CompositePattern/
├── 04_DecoratorPattern/
├── 05_FacadePattern/
├── 06_FlyweightPattern/
└── 07_ProxyPattern/
```

Each pattern directory contains:
- README.md: Detailed pattern explanation
- Implementation in multiple languages (Java/C++)
- Examples of both good and bad implementations

## When to Use Which Pattern

- **Adapter**: When you need to make incompatible classes work together
- **Bridge**: When you want to separate an abstraction from its implementation
- **Composite**: When you need to treat individual objects and compositions uniformly
- **Decorator**: When you need to add responsibilities to objects dynamically
- **Facade**: When you need to simplify a complex subsystem
- **Flyweight**: When you need to support large numbers of similar objects efficiently
- **Proxy**: When you need to control access to an object
