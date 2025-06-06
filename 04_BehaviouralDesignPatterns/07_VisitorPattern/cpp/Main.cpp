#include <iostream>
#include <vector>
#include <memory>

// Forward declarations
class PhysicalProduct;
class DigitalProduct;
class GiftCard;

// Visitor interface
class ProductVisitor {
public:
    virtual void visit(const PhysicalProduct& product) = 0;
    virtual void visit(const DigitalProduct& product) = 0;
    virtual void visit(const GiftCard& card) = 0;
    virtual ~ProductVisitor() = default;
};

// Product interface
class Product {
public:
    virtual void accept(ProductVisitor& visitor) = 0;
    virtual ~Product() = default;
};

// Concrete products
class PhysicalProduct : public Product {
public:
    void accept(ProductVisitor& visitor) override {
        visitor.visit(*this);
    }

    double getWeight() const {
        return 2.5; // Example weight in kg
    }

    double getSize() const {
        return 10.0; // Example size in cubic meters
    }
};

class DigitalProduct : public Product {
public:
    void accept(ProductVisitor& visitor) override {
        visitor.visit(*this);
    }

    double getFileSize() const {
        return 1.5; // Example size in GB
    }
};

class GiftCard : public Product {
public:
    void accept(ProductVisitor& visitor) override {
        visitor.visit(*this);
    }

    double getValue() const {
        return 50.0; // Example value in dollars
    }
};

// Concrete visitors
class InvoicePrinter : public ProductVisitor {
public:
    void visit(const PhysicalProduct& product) override {
        std::cout << "Printing invoice for physical product:" << std::endl;
        std::cout << "Weight: " << product.getWeight() << " kg" << std::endl;
        std::cout << "Size: " << product.getSize() << " cubic meters" << std::endl;
    }

    void visit(const DigitalProduct& product) override {
        std::cout << "Printing invoice for digital product:" << std::endl;
        std::cout << "File size: " << product.getFileSize() << " GB" << std::endl;
    }

    void visit(const GiftCard& card) override {
        std::cout << "Printing invoice for gift card:" << std::endl;
        std::cout << "Value: $" << card.getValue() << std::endl;
    }
};

class ShippingCalculator : public ProductVisitor {
public:
    void visit(const PhysicalProduct& product) override {
        double cost = 5.99 + (product.getWeight() * 2.0);
        std::cout << "Shipping cost for physical product: $" << cost << std::endl;
    }

    void visit(const DigitalProduct&) override {
        std::cout << "No shipping cost for digital product" << std::endl;
    }

    void visit(const GiftCard&) override {
        std::cout << "No shipping cost for gift card" << std::endl;
    }
};

class DiscountCalculator : public ProductVisitor {
public:
    void visit(const PhysicalProduct&) override {
        std::cout << "Standard 5% discount for physical product" << std::endl;
    }

    void visit(const DigitalProduct&) override {
        std::cout << "No discount for digital product" << std::endl;
    }

    void visit(const GiftCard& card) override {
        double discount = card.getValue() * 0.1; // 10% discount
        std::cout << "Gift card discount: $" << discount << std::endl;
    }
};

int main() {
    // Create products
    std::vector<std::unique_ptr<Product>> products;
    products.push_back(std::make_unique<PhysicalProduct>());
    products.push_back(std::make_unique<DigitalProduct>());
    products.push_back(std::make_unique<GiftCard>());

    // Create visitors
    InvoicePrinter invoicePrinter;
    ShippingCalculator shippingCalculator;
    DiscountCalculator discountCalculator;

    std::cout << "Processing all products:\n" << std::endl;

    // Process each product with all visitors
    for (const auto& product : products) {
        product->accept(invoicePrinter);
        product->accept(shippingCalculator);
        product->accept(discountCalculator);
        std::cout << "------------------------" << std::endl;
    }

    return 0;
}