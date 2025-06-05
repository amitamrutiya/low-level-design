/*
 * Issues with this implementation:
 * 1. Violates Open-Closed Principle: LogisticService needs modification every time a new delivery mode is added
 * 2. High coupling: LogisticService directly creates concrete implementations (Truck, Ship, Airplane)
 * 3. Complex conditional logic: Uses if-else chains which can grow unmanageable
 * 4. Poor maintainability: Adding new transport types requires changing multiple places
 * 5. Hard to test: Each new transport type requires modifying existing code
 * 
 * These issues can be solved using Factory Method Pattern which:
 * - Delegates object creation to specialized factory classes
 * - Makes code more extensible
 * - Removes direct dependencies on concrete classes
 */

interface Logistics {
    void send();
}

class Truck implements Logistics {
    @Override
    public void send() {
        System.out.println("Delivering by Truck");
    }
}

class Ship implements Logistics {
    @Override
    public void send() {
        System.out.println("Delivering by Ship");
    }
}

class Airplane implements Logistics {
    @Override
    public void send() {
        System.out.println("Delivering by Airplane");
    }

}

class LogisticService {
    public void deliver(String mode) {
        if (mode.equals("Truck")) {
            Logistics truck = new Truck();
            truck.send();
        } else if (mode.equals("Ship")) {
            Logistics ship = new Ship();
            ship.send();
        } else if (mode.equals("Airplane")) {
            Logistics airplane = new Airplane();
            airplane.send();
        } else {
            throw new IllegalArgumentException("Unknown delivery mode: " + mode);
        }
    }
}

public class BadCode {
    public static void main(String[] args) {
        LogisticService service = new LogisticService();
        service.deliver("Truck"); // Delivering by Truck
        service.deliver("Ship"); // Delivering by Ship
        service.deliver("Airplane"); // Delivering by Airplane
        // service.deliver("Bike"); // Uncommenting this line will throw an exception
    }
}