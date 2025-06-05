#include <iostream>
#include <string>
#include <memory>

// Tax strategy Interface
class TaxCalculator {
public:
    virtual double calculateTax(double amount) = 0;
    virtual ~TaxCalculator() = default;
};

// Implementing Region-Specific Tax Calculators
class IndiaTaxCalculator : public TaxCalculator {
public:
    double calculateTax(double amount) override {
        return amount * 0.18; // GST
    }
};

class USTaxCalculator : public TaxCalculator {
public:
    double calculateTax(double amount) override {
        return amount * 0.08; // Sales Tax
    }
};

class UKTaxCalculator : public TaxCalculator {
public:
    double calculateTax(double amount) override {
        return amount * 0.12; // VAT
    }
};

// Using dependency Injection
class Invoice {
private:
    double amount;
    std::shared_ptr<TaxCalculator> taxCalculator;

public:
    Invoice(double amount, std::shared_ptr<TaxCalculator> calculator) 
        : amount(amount), taxCalculator(calculator) {}

    double getTotalAmount() {
        return amount + taxCalculator->calculateTax(amount);
    }
};

int main() {
    double amount = 1000.0;

    Invoice indiaInvoice(amount, std::make_shared<IndiaTaxCalculator>());
    std::cout << "Total (India): ₹" << indiaInvoice.getTotalAmount() << std::endl;

    Invoice usInvoice(amount, std::make_shared<USTaxCalculator>());
    std::cout << "Total (US): $" << usInvoice.getTotalAmount() << std::endl;

    Invoice ukInvoice(amount, std::make_shared<UKTaxCalculator>());
    std::cout << "Total (UK): £" << ukInvoice.getTotalAmount() << std::endl;

    return 0;
}
