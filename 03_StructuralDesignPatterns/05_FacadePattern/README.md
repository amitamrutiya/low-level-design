# Facade Pattern

## Definition
The Facade Pattern provides a unified interface to a set of interfaces in a subsystem. It defines a higher-level interface that makes the subsystem easier to use by reducing complexity and hiding implementation details.

## Key Points
- Simplifies complex system interface
- Provides a single entry point to subsystem
- Reduces coupling between client and subsystem
- Follows principle of least knowledge

## Example Implementation
The example shows a home theater system:
- `HomeTheaterFacade`: Unified interface
- Multiple subsystems: `Projector`, `SoundSystem`, `Lights`, etc.
- Complex operations simplified into single method calls

## Class Diagram
```
+------------------+
| HomeTheaterFacade|
+------------------+      +------------+
| -projector      |----->| Projector  |
| -soundSystem    |----->+------------+
| -lights         |      
| +watchMovie()   |      +------------+
| +endMovie()     |----->|SoundSystem |
+------------------+      +------------+
                         
                         +------------+
                         |  Lights    |
                         +------------+
```

## Benefits
1. Shields clients from subsystem components
2. Promotes weak coupling
3. Simplifies usage of complex systems
4. Helps in layering subsystems

## Cons/Challenges
1. Can become a god object/anti-pattern if overused
2. May hide useful complexity
3. Can introduce a single point of failure
4. May decrease flexibility in accessing subsystem components
