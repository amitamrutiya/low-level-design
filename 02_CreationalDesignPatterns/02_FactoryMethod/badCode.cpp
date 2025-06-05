#include <iostream>
#include <string>
using namespace std;

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

class Logistics {
public:
    virtual void send() = 0;
    virtual ~Logistics() = default;
};

class Truck : public Logistics {
public:
    void send() override {
        cout << "Delivering by Truck" << endl;
    }
};

class Ship : public Logistics {
public:
    void send() override {
        cout << "Delivering by Ship" << endl;
    }
};

class Airplane : public Logistics {
public:
    void send() override {
        cout << "Delivering by Airplane" << endl;
    }
};

class LogisticService {
public:
    void deliver(const string& mode) {
        if (mode == "Truck") {
            Logistics* truck = new Truck();
            truck->send();
            delete truck;
        } else if (mode == "Ship") {
            Logistics* ship = new Ship();
            ship->send();
            delete ship;
        } else if (mode == "Airplane") {
            Logistics* airplane = new Airplane();
            airplane->send();
            delete airplane;
        } else {
            throw invalid_argument("Unknown delivery mode: " + mode);
        }
    }
};

int main() {
    LogisticService service;
    service.deliver("Truck");    // Delivering by Truck
    service.deliver("Ship");     // Delivering by Ship
    service.deliver("Airplane"); // Delivering by Airplane
    // service.deliver("Bike"); // Uncommenting this line will throw an exception
    return 0;
}
