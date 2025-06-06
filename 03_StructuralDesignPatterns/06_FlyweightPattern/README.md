# Flyweight Pattern

## Definition
The Flyweight Pattern is a structural design pattern that minimizes memory usage by sharing as much data as possible with similar objects. It's used when you need to create a large number of similar objects efficiently.

## Key Points
- Reduces memory usage by sharing common state
- Separates intrinsic and extrinsic state
- Uses factory for object creation and caching
- Best for systems with large numbers of similar objects

## Example Implementation
The example demonstrates a text editor formatting system:
- `Character`: Flyweight interface
- `CharacterFlyweight`: Concrete flyweight
- `FontFactory`: Flyweight factory
- Shared state: font properties
- Unshared state: position, color

## Class Diagram
```
+-------------+     +------------------+
| FontFactory |---->| CharacterFlyweight|
+-------------+     +------------------+
| +getFont()  |     | -font: String    |
| -cache      |     | -size: int       |
+-------------+     | +render()        |
                    +------------------+
                            ▲
                    +-------+-------+
                    |               |
              +---------+    +---------+
              | BoldFont|    |ItalicFont|
              +---------+    +---------+
```

## Benefits
1. Reduces memory usage significantly
2. Improves performance with object caching
3. Reduces object creation overhead
4. Centralizes state management

## Cons/Challenges
1. Complex to implement correctly
2. Can complicate code if overused
3. Difficult to handle mutable state
4. May trade CPU cycles for memory savings
