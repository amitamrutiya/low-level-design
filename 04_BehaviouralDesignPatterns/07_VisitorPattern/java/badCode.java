class PhysicalProduct {
    void printInvoice() {
        System.out.println("Printing invoice for physical product.");
    }

    double calculateShippingCost() {
        return 5.99; // Flat shipping cost for physical products
    }
}

class DigitalProduct {
    void printInvoice() {
        System.out.println("Printing invoice for digital product.");
    }
    // no shipping cost for digital products
}

class GiftCard {
    void printInvoice() {
        System.out.println("Printing invoice for gift card.");
    }

    double calculateDiscount() {
        return 10.00; // Flat discount for gift cards
    }
}

public class badCode {
    public static void main(String[] args) {
        PhysicalProduct physicalProduct = new PhysicalProduct();
        DigitalProduct digitalProduct = new DigitalProduct();
        GiftCard giftCard = new GiftCard();

        // Printing invoices
        physicalProduct.printInvoice();
        digitalProduct.printInvoice();
        giftCard.printInvoice();

        // Calculating shipping cost for physical product
        double shippingCost = physicalProduct.calculateShippingCost();
        System.out.println("Shipping cost for physical product: $" + shippingCost);

        // Calculating discount for gift card
        double discount = giftCard.calculateDiscount();
        System.out.println("Discount for gift card: $" + discount);

        for (Item item : cart) {
            if (item instanceof PhysicalProduct) {
                ((PhysicalProduct) item).printInvoice();
                double shippingCost = ((PhysicalProduct) item).calculateShippingCost();
                System.out.println("Shipping cost for physical product: $" + shippingCost);
            } else if (item instanceof DigitalProduct) {
                ((DigitalProduct) item).printInvoice();
            } else if (item instanceof GiftCard) {
                ((GiftCard) item).printInvoice();
                double discount = ((GiftCard) item).calculateDiscount();
                System.out.println("Discount for gift card: $" + discount);
            }
        }
    }
}