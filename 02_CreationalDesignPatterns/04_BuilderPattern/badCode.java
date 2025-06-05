/*
 * Problems with this code that Builder Pattern would solve:
 * 1. Telescoping constructor anti-pattern - A single constructor with too many parameters
 * 2. Poor readability in client code - Hard to remember parameter order and meaning
 * 3. No immutability - All fields are mutable after construction
 * 4. Null values for optional parameters - Leads to potential NullPointerExceptions
 * 5. No way to enforce required vs optional parameters
 * 6. No validation during object construction
 */

class BurgerMeal {
    private String bun;
    private String patty;
    private String cheese; // optional
    private String sauce; // optional
    private String side; // optional
    private String drink; // optional

    public BurgerMeal(String bun, String patty, String cheese, String sauce, String side, String drink) {
        this.bun = bun;
        this.patty = patty;
        this.cheese = cheese;
        this.sauce = sauce;
        this.side = side;
        this.drink = drink;
    }
}

public class badCode {
    public static void main(String[] args) {
        // Problem 1: Poor readability - Hard to track what each parameter means
        BurgerMeal meal1 = new BurgerMeal("Sesame Bun", "Beef Patty", "Cheddar Cheese", "Ketchup", "Fries", "Coke");

        // Problem 2: Using null for optional parameters - Bad practice
        // Problem 3: No validation for required parameters
        BurgerMeal meal3 = new BurgerMeal("Gluten-Free Bun", "Veggie Patty", null, null, null, null);
    }
}