# Decorator Pattern

## Definition
The Decorator Pattern is a structural design pattern that allows behavior to be added to individual objects dynamically without affecting the behavior of other objects from the same class.

## Key Points
- Adds responsibilities to objects dynamically
- Provides flexible alternative to subclassing
- Follows Single Responsibility Principle
- Supports Open/Closed Principle

## Example Implementation
The example demonstrates a pizza ordering system:
- `Pizza`: Base interface
- `PlainPizza`: Concrete component
- `ToppingDecorator`: Abstract decorator
- `CheeseDecorator`, `OliveDecorator`: Concrete decorators

## Class Diagram
```
+-------------+
|   Pizza     |
+-------------+
| +cost()     |
| +getDesc()  |
+-------------+
      ▲
      |
+------------+    +------------------+
| PlainPizza |    | ToppingDecorator|
+------------+    +------------------+
                  | -pizza: Pizza    |
                  +------------------+
                           ▲
                   +-------+-------+
                   |               |
            +-----------+  +------------+
            |CheeseTopping| |OliveTopping|
            +-----------+  +------------+
```

## Benefits
1. More flexibility than static inheritance
2. Avoids class explosion from feature combinations
3. Supports Single Responsibility Principle
4. Allows responsibilities to be added/removed at runtime

## Cons/Challenges
1. Can result in many small decorator classes
2. Order of decorators can be important
3. Can be complex to initialize
4. May complicate the code structure
