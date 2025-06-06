#include <iostream>
#include <vector>
#include <memory>

class PhysicalProduct {
public:
    void printInvoice() const {
        std::cout << "Printing invoice for physical product." << std::endl;
    }

    double calculateShippingCost() const {
        return 5.99; // Flat shipping cost for physical products
    }
};

class DigitalProduct {
public:
    void printInvoice() const {
        std::cout << "Printing invoice for digital product." << std::endl;
    }
    // no shipping cost for digital products
};

class GiftCard {
public:
    void printInvoice() const {
        std::cout << "Printing invoice for gift card." << std::endl;
    }

    double calculateDiscount() const {
        return 10.00; // Flat discount for gift cards
    }
};

// Base class for type checking
class Item {
public:
    virtual ~Item() = default;
};

// Derived classes for type checking
class PhysicalProductItem : public Item, public PhysicalProduct {};
class DigitalProductItem : public Item, public DigitalProduct {};
class GiftCardItem : public Item, public GiftCard {};

int main() {
    PhysicalProduct physicalProduct;
    DigitalProduct digitalProduct;
    GiftCard giftCard;

    // Printing invoices
    physicalProduct.printInvoice();
    digitalProduct.printInvoice();
    giftCard.printInvoice();

    // Calculating shipping cost for physical product
    double shippingCost = physicalProduct.calculateShippingCost();
    std::cout << "Shipping cost for physical product: $" << shippingCost << std::endl;

    // Calculating discount for gift card
    double discount = giftCard.calculateDiscount();
    std::cout << "Discount for gift card: $" << discount << std::endl;

    // Example with a collection of items
    std::vector<std::unique_ptr<Item>> cart;
    cart.push_back(std::make_unique<PhysicalProductItem>());
    cart.push_back(std::make_unique<DigitalProductItem>());
    cart.push_back(std::make_unique<GiftCardItem>());

    for (const auto& item : cart) {
        if (auto* physical = dynamic_cast<PhysicalProductItem*>(item.get())) {
            physical->printInvoice();
            double cost = physical->calculateShippingCost();
            std::cout << "Shipping cost for physical product: $" << cost << std::endl;
        }
        else if (auto* digital = dynamic_cast<DigitalProductItem*>(item.get())) {
            digital->printInvoice();
        }
        else if (auto* gift = dynamic_cast<GiftCardItem*>(item.get())) {
            gift->printInvoice();
            double disc = gift->calculateDiscount();
            std::cout << "Discount for gift card: $" << disc << std::endl;
        }
    }

    return 0;
}