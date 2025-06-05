#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class BurgerMeal {
private:
    // Required parameters
    string bun;
    string patty;

    // Optional parameters
    bool hasCheese;
    string sauce;
    string side;
    string drink;
    vector<string> toppings;

    // Private constructor to enforce use of Builder
    BurgerMeal(const class BurgerBuilder& builder);

public:
    // Builder class declaration
    class BurgerBuilder {
    private:
        // Required parameters
        string bun;
        string patty;

        // Optional parameters - initialized to default values
        bool hasCheese = false;
        string sauce;
        string side;
        string drink;
        vector<string> toppings;

    public:
        BurgerBuilder(const string& bun, const string& patty) 
            : bun(bun), patty(patty) {}

        BurgerBuilder& withCheese() {
            this->hasCheese = true;
            return *this;
        }

        BurgerBuilder& withSauce(const string& sauce) {
            this->sauce = sauce;
            return *this;
        }

        BurgerBuilder& withSide(const string& side) {
            this->side = side;
            return *this;
        }

        BurgerBuilder& withDrink(const string& drink) {
            this->drink = drink;
            return *this;
        }

        BurgerBuilder& addTopping(const string& topping) {
            this->toppings.push_back(topping);
            return *this;
        }

        unique_ptr<BurgerMeal> build() {
            return unique_ptr<BurgerMeal>(new BurgerMeal(*this));
        }

        // Friend declaration to allow BurgerMeal to access private members
        friend class BurgerMeal;
    };
};

// BurgerMeal constructor implementation
BurgerMeal::BurgerMeal(const BurgerBuilder& builder) 
    : bun(builder.bun),
      patty(builder.patty),
      hasCheese(builder.hasCheese),
      sauce(builder.sauce),
      side(builder.side),
      drink(builder.drink),
      toppings(builder.toppings) {}

int main() {
    // Using the Builder pattern to create a BurgerMeal
    auto meal1 = BurgerMeal::BurgerBuilder("Sesame Bun", "Beef Patty")
        .withCheese()
        .withSauce("Ketchup")
        .withSide("Fries")
        .withDrink("Coke")
        .addTopping("Lettuce")
        .addTopping("Tomato")
        .build();

    // Another meal with different options
    auto meal2 = BurgerMeal::BurgerBuilder("Gluten-Free Bun", "Veggie Patty")
        .withSauce("Mustard")
        .withSide("Salad")
        .build();

    return 0;
}
