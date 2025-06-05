#include <iostream>
#include <string>
#include <memory>
using namespace std;

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

class LogisticsFactory {
public:
    static unique_ptr<Logistics> createLogistics(const string& mode) {
        if (mode == "Truck") {
            return make_unique<Truck>();
        } else if (mode == "Ship") {
            return make_unique<Ship>();
        } else if (mode == "Airplane") {
            return make_unique<Airplane>();
        } else {
            throw invalid_argument("Unknown delivery mode: " + mode);
        }
    }
};

class LogisticService {
public:
    void deliver(const string& mode) {
        auto logistics = LogisticsFactory::createLogistics(mode);
        logistics->send();
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
