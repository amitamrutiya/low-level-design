#include <iostream>
#include <string>
using namespace std;

class PlainPizza {};
class CheesePizza : public PlainPizza {};
class OlivePizza : public PlainPizza {};
class StuffedPizza : public PlainPizza {};
class CheeseStuffedPizza : public CheesePizza {};
class CheeseOlivePizza : public CheesePizza {};
class CheeseOliveStuffedPizza : public CheeseOlivePizza {};

int main() {
    // Base pizza
    PlainPizza plainPizza;

    // Pizzas with individual toppings
    CheesePizza cheesePizza;
    OlivePizza olivePizza;
    StuffedPizza stuffedPizza;

    // Combinations of toppings require separate classes
    CheeseStuffedPizza cheeseStuffedPizza;
    CheeseOlivePizza cheeseOlivePizza;

    // Further combinations increase complexity exponentially
    CheeseOliveStuffedPizza cheeseOliveStuffedPizza;

    cout << "Created various pizza types without using Decorator Pattern" << endl;
    cout << "This approach leads to class explosion as each combination needs a new class" << endl;

    return 0;
}