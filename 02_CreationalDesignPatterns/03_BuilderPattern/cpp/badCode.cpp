#include <iostream>
#include <string>
using namespace std;

/*
 * Problems with this code that Builder Pattern would solve:
 * 1. Telescoping constructor anti-pattern - A single constructor with too many parameters
 * 2. Poor readability in client code - Hard to remember parameter order and meaning
 * 3. No immutability - All fields are mutable after construction
 * 4. Null values for optional parameters - Leads to potential runtime_error
 * 5. No way to enforce required vs optional parameters
 * 6. No validation during object construction
 */

class BurgerMeal {
private:
    string bun;
    string patty;
    string cheese;  // optional
    string sauce;   // optional
    string side;    // optional
    string drink;   // optional

public:
    BurgerMeal(const string& bun, const string& patty, 
               const string& cheese, const string& sauce, 
               const string& side, const string& drink)
        : bun(bun), patty(patty), cheese(cheese), sauce(sauce), side(side), drink(drink) {}
};

int main() {
    // Problem 1: Poor readability - Hard to track what each parameter means
    BurgerMeal meal1("Sesame Bun", "Beef Patty", "Cheddar Cheese", "Ketchup", "Fries", "Coke");

    // Problem 2: Using empty strings for optional parameters - Bad practice
    // Problem 3: No validation for required parameters
    BurgerMeal meal3("Gluten-Free Bun", "Veggie Patty", "", "", "", "");

    return 0;
}
