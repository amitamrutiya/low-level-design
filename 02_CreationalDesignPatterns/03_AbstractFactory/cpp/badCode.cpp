#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class PaymentGateway {
public:
    virtual void processPayment(double amount) = 0;
    virtual ~PaymentGateway() = default;
};

class RazorpayGateway : public PaymentGateway {
public:
    void processPayment(double amount) override {
        cout << "Processing payment of " << amount << " using Razorpay" << endl;
    }
};

class PayUGateway : public PaymentGateway {
public:
    void processPayment(double amount) override {
        cout << "Processing payment of " << amount << " using PayU" << endl;
    }
};

class Invoice {
public:
    virtual void generateInvoice() = 0;
    virtual ~Invoice() = default;
};

class GSTInvoice : public Invoice {
public:
    void generateInvoice() override {
        cout << "Generating GST Invoice for India" << endl;
    }
};

// VIOLATION 1: Abstract Factory Pattern Violations:
// 1. Missing abstract factory interface that defines contract for creating
// payment gateways and invoices
// 2. Factory implementation is tightly coupled with concrete classes
// 3. Static methods prevent flexibility and make testing difficult
// 4. No separation between factory interface and implementation
class IndiaFactory {
public:
    static PaymentGateway* createPaymentGateway(const string& type) {
        if (type == "Razorpay") {
            return new RazorpayGateway();
        } else if (type == "PayU") {
            return new PayUGateway();
        } else {
            throw invalid_argument("Unknown payment gateway: " + type);
        }
    }

    static Invoice* createInvoice() {
        return new GSTInvoice();
    }
};

class CheckoutService {
private:
    string gatewayType;
    string countryCode;

public:
    CheckoutService(const string& gType, const string& cCode)
        : gatewayType(gType), countryCode(cCode) {}

    void checkOut(double amount) {
        // VIOLATION 2: Violating Abstract Factory Pattern:
        // 1. Direct instantiation of concrete classes instead of using factory
        // 2. Hard-coded country check instead of using abstract factory
        // 3. Should use a factory provider to get the appropriate country factory
        // 4. Tight coupling with IndiaFactory implementation
        if (countryCode == "INDIA") {
            PaymentGateway* paymentGateway = IndiaFactory::createPaymentGateway(gatewayType);
            paymentGateway->processPayment(amount);
            Invoice* invoice = IndiaFactory::createInvoice();
            invoice->generateInvoice();
            delete paymentGateway;
            delete invoice;
        } else {
            // VIOLATION 3: Missing implementations for other countries
            // Should have concrete factories for each country implementing the abstract
            // factory interface
        }
    }
};

int main() {
    CheckoutService service("Razorpay", "INDIA");
    service.checkOut(1000.0);
    return 0;
}
