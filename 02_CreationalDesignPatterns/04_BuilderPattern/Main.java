import java.util.*;

class BurgerMeal {
    // Required parameters
    private final String bun;
    private final String patty;

    // Optional parameters
    private final boolean hasCheese;
    private final String sauce;
    private final String side;
    private final String drink;
    private final List<String> toppings;

    // Private constructor to enforce use of Builder
    private BurgerMeal(BurgerBuilder builder) {
        this.bun = builder.bun;
        this.patty = builder.patty;
        this.hasCheese = builder.hasCheese;
        this.sauce = builder.sauce;
        this.side = builder.side;
        this.drink = builder.drink;
        this.toppings = builder.toppings;
    }

    public static class BurgerBuilder {
        // Required parameters
        private final String bun;
        private final String patty;

        // Optional parameters
        private boolean hasCheese = false;
        private String sauce = "";
        private String side = "";
        private String drink = "";
        private List<String> toppings = new ArrayList<>();

        public BurgerBuilder(String bun, String patty) {
            this.bun = bun;
            this.patty = patty;
        }

        public BurgerBuilder withCheese() {
            this.hasCheese = true;
            return this;
        }

        public BurgerBuilder withSauce(String sauce) {
            this.sauce = sauce;
            return this;
        }

        public BurgerBuilder withSide(String side) {
            this.side = side;
            return this;
        }

        public BurgerBuilder withDrink(String drink) {
            this.drink = drink;
            return this;
        }

        public BurgerBuilder addTopping(String topping) {
            this.toppings.add(topping);
            return this;
        }

        public BurgerMeal build() {
            return new BurgerMeal(this);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        // Using the Builder pattern to create a BurgerMeal
        BurgerMeal meal1 = new BurgerMeal.BurgerBuilder("Sesame Bun", "Beef Patty")
                .withCheese()
                .withSauce("Ketchup")
                .withSide("Fries")
                .withDrink("Coke")
                .addTopping("Lettuce")
                .addTopping("Tomato")
                .build();

        // Another meal with different options
        BurgerMeal meal2 = new BurgerMeal.BurgerBuilder("Gluten-Free Bun", "Veggie Patty")
                .withSauce("Mustard")
                .withSide("Salad")
                .build();

        // Print out the meals (toString method can be added for better output)
        System.out.println(meal1);
        System.out.println(meal2);
    }
}