#include <iostream>
#include <string>

class InvoiceProcessor {
public:
    double calculateTotal(const std::string& region, double amount) {
        if (region == "India") {
            return amount + amount * 0.18;
        } else if (region == "US") {
            return amount + amount * 0.08;
        } else if (region == "UK") {
            return amount + amount * 0.12;
        } else {
            return amount; // No tax for unknown region
        }
    }
};

int main() {
    InvoiceProcessor processor;
    double amount = 1000.0;
    
    std::cout << "Total (India): ₹" << processor.calculateTotal("India", amount) << std::endl;
    std::cout << "Total (US): $" << processor.calculateTotal("US", amount) << std::endl;
    std::cout << "Total (UK): £" << processor.calculateTotal("UK", amount) << std::endl;
    
    return 0;
}
