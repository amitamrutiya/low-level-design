#include <iostream>
#include <string>
using namespace std;

// Base Pizza interface
class Pizza {
public:
    virtual string getDescription() = 0;
    virtual double getCost() = 0;
    virtual ~Pizza() = default;
};

// Concrete Components: Base pizzas
class PlainPizza : public Pizza {
public:
    string getDescription() override {
        return "Plain Pizza";
    }

    double getCost() override {
        return 150.00;
    }
};

class MargheritaPizza : public Pizza {
public:
    string getDescription() override {
        return "Margherita Pizza";
    }

    double getCost() override {
        return 200.00;
    }
};

// Abstract Decorator class
class PizzaDecorator : public Pizza {
protected:
    Pizza* pizza;  // Note: Using pointer instead of reference for dynamic composition

public:
    explicit PizzaDecorator(Pizza* p) : pizza(p) {}
    virtual ~PizzaDecorator() {
        delete pizza;  // Clean up the decorated pizza
    }
    
    string getDescription() override {
        return pizza->getDescription();
    }
    
    double getCost() override {
        return pizza->getCost();
    }
};

// Concrete Decorator: Adds Extra Cheese
class ExtraCheese : public PizzaDecorator {
public:
    explicit ExtraCheese(Pizza* pizza) : PizzaDecorator(pizza) {}

    string getDescription() override {
        return pizza->getDescription() + ", Extra Cheese";
    }

    double getCost() override {
        return pizza->getCost() + 40.0;
    }
};

// Concrete Decorator: Adds Olives
class Olives : public PizzaDecorator {
public:
    explicit Olives(Pizza* pizza) : PizzaDecorator(pizza) {}

    string getDescription() override {
        return pizza->getDescription() + ", Olives";
    }

    double getCost() override {
        return pizza->getCost() + 30.0;
    }
};

// Concrete Decorator: Adds Stuffed Crust
class StuffedCrust : public PizzaDecorator {
public:
    explicit StuffedCrust(Pizza* pizza) : PizzaDecorator(pizza) {}

    string getDescription() override {
        return pizza->getDescription() + ", Stuffed Crust";
    }

    double getCost() override {
        return pizza->getCost() + 50.0;
    }
};

// Driver code
int main() {
    // Start with a basic Margherita Pizza
    Pizza* myPizza = new MargheritaPizza();

    // Add Extra Cheese
    myPizza = new ExtraCheese(myPizza);

    // Add Olives
    myPizza = new Olives(myPizza);

    // Add Stuffed Crust
    myPizza = new StuffedCrust(myPizza);

    // Final Description and Cost
    cout << "Pizza Description: " << myPizza->getDescription() << endl;
    cout << "Total Cost: ₹" << myPizza->getCost() << endl;

    // Clean up
    delete myPizza;  // Will cascade through the chain of decorators

    return 0;
}