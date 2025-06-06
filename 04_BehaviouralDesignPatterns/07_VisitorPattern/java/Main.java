
import java.util.ArrayList;
import java.util.List;

interface Item {
    void accept(ItemVisitor visitor);
}

interface ItemVisitor {
    void visit(PhysicalProduct physicalProduct);

    void visit(DigitalProduct digitalProduct);

    void visit(GiftCard giftCard);
}

class PhysicalProduct implements Item {
    String name;
    double weight;

    public PhysicalProduct(String name, double weight) {
        this.name = name;
        this.weight = weight;
    }

    @Override
    public void accept(ItemVisitor visitor) {
        visitor.visit(this);
    }
}

class DigitalProduct implements Item {
    String name;
    double size;

    public DigitalProduct(String name, double size) {
        this.name = name;
        this.size = size;
    }

    @Override
    public void accept(ItemVisitor visitor) {
        visitor.visit(this);
    }
}

class GiftCard implements Item {
    String code;
    double value;

    public GiftCard(String code, double value) {
        this.code = code;
        this.value = value;
    }

    @Override
    public void accept(ItemVisitor visitor) {
        visitor.visit(this);
    }
}

class InvoiceVisitor implements ItemVisitor {
    @Override
    public void visit(PhysicalProduct physicalProduct) {
        System.out.println("Printing invoice for physical product: " + physicalProduct.name);
    }

    @Override
    public void visit(DigitalProduct digitalProduct) {
        System.out.println("Printing invoice for digital product: " + digitalProduct.name);
    }

    @Override
    public void visit(GiftCard giftCard) {
        System.out.println("Printing invoice for gift card: " + giftCard.code);
    }
}

class ShippingCostVisitor implements ItemVisitor {
    @Override
    public void visit(PhysicalProduct physicalProduct) {
        System.out.println("Shipping cost for physical product: $" + (physicalProduct.weight * 0.5));
    }

    @Override
    public void visit(DigitalProduct digitalProduct) {
        System.out.println("No shipping cost for digital product: " + digitalProduct.name);
    }

    @Override
    public void visit(GiftCard giftCard) {
        System.out.println("No shipping cost for gift card: " + giftCard.code);
    }
}

public class Main {
    public static void main(String[] args) {
        List<Item> items = new ArrayList<>();
        Item physicalProduct = new PhysicalProduct("Laptop", 2.5);
        Item digitalProduct = new DigitalProduct("E-book", 0.1);
        Item giftCard = new GiftCard("GC12345", 50.0);

        items.add(physicalProduct);
        items.add(digitalProduct);
        items.add(giftCard);

        ItemVisitor invoiceVisitor = new InvoiceVisitor();
        ItemVisitor shippingCostVisitor = new ShippingCostVisitor();

        for (Item item : items) {
            item.accept(invoiceVisitor);
            item.accept(shippingCostVisitor);
        }
    }
}
