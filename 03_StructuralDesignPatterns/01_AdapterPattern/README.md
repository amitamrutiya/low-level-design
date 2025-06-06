# Adapter Pattern

## Definition
The Adapter Pattern is a structural design pattern that allows incompatible interfaces to work together. It acts as a bridge between two incompatible interfaces by wrapping an object in an adapter to make it compatible with another class.

## Key Points
- Converts the interface of a class into another interface that clients expect
- Enables classes to work together that couldn't otherwise because of incompatible interfaces
- Can be implemented using either inheritance (class adapter) or composition (object adapter)
- Helps achieve reusability and flexibility

## Example Implementation
The example shows how to adapt a legacy payment system to work with a new modern payment interface:
- `LegacyPaymentSystem`: Old payment processing system
- `ModernPaymentInterface`: New payment interface specification
- `PaymentAdapter`: Adapter that makes legacy system work with new interface

## Class Diagram
```
+------------------------+      +-----------------------+
|  ModernPaymentInterface|      |   LegacyPaymentSystem|
+------------------------+      +-----------------------+
| +processPayment()      |      | +oldProcessPayment() |
+------------------------+      +-----------------------+
           ▲                            ▲
           |                            |
           |                            |
    +------------------+         |
    |  PaymentAdapter  |-----------------+
    +------------------+
    | +processPayment()|
    +------------------+
```

## Benefits
1. Increases reusability of older code
2. Provides flexibility in terms of interface design
3. Helps achieve single responsibility principle
4. Makes incompatible interfaces compatible

## Cons/Challenges
1. Increases overall code complexity
2. Sometimes hard to implement if many interfaces need to be adapted
3. May require lots of adapters for a complex system
4. Can be confusing for developers new to the codebase
