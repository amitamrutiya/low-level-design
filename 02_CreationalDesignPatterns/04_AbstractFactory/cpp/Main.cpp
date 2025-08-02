#include <iostream>
#include <string>
#include <memory>
using namespace std;

// Payment Gateway Interface
class PaymentGateway {
public:
    virtual void processPayment(double amount) = 0;
    virtual ~PaymentGateway() = default;
};

// Concrete Payment Gateway implementations
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

class PaypalGateway : public PaymentGateway {
public:
    void processPayment(double amount) override {
        cout << "Processing payment of " << amount << " using PayPal" << endl;
    }
};

class StripeGateway : public PaymentGateway {
public:
    void processPayment(double amount) override {
        cout << "Processing payment of " << amount << " using Stripe" << endl;
    }
};

// Invoice Interface
class Invoice {
public:
    virtual void generateInvoice() = 0;
    virtual ~Invoice() = default;
};

// Concrete Invoice implementation
class GSTInvoice : public Invoice {
public:
    void generateInvoice() override {
        cout << "Generating GST Invoice for India" << endl;
    }
};

// Abstract Factory Interface
class RegionFactory {
public:
    virtual unique_ptr<PaymentGateway> createPaymentGateway(const string& type) = 0;
    virtual unique_ptr<Invoice> createInvoice() = 0;
    virtual ~RegionFactory() = default;
};

// Concrete Factory for India
class IndiaFactory : public RegionFactory {
public:
    unique_ptr<PaymentGateway> createPaymentGateway(const string& type) override {
        if (type == "Razorpay") {
            return make_unique<RazorpayGateway>();
        } else if (type == "PayU") {
            return make_unique<PayUGateway>();
        } else {
            throw invalid_argument("Unknown payment gateway: " + type);
        }
    }

    unique_ptr<Invoice> createInvoice() override {
        return make_unique<GSTInvoice>();
    }
};

// Concrete Factory for US
class USFactory : public RegionFactory {
public:
    unique_ptr<PaymentGateway> createPaymentGateway(const string& type) override {
        if (type == "PayPal") {
            return make_unique<PaypalGateway>();
        } else if (type == "Stripe") {
            return make_unique<StripeGateway>();
        } else {
            throw invalid_argument("Unknown payment gateway: " + type);
        }
    }

    unique_ptr<Invoice> createInvoice() override {
        return nullptr; // Placeholder for US-specific invoice
    }
};

// Service using the factories
class CheckoutService {
private:
    unique_ptr<PaymentGateway> paymentGateway;
    unique_ptr<Invoice> invoice;

public:
    CheckoutService(RegionFactory& factory, const string& gatewayType) {
        paymentGateway = factory.createPaymentGateway(gatewayType);
        invoice = factory.createInvoice();
    }

    void completeOrder(double amount) {
        paymentGateway->processPayment(amount);
        if (invoice) {
            invoice->generateInvoice();
        }
    }
};

int main() {
    IndiaFactory indiaFactory;
    USFactory usFactory;

    {
        CheckoutService service(indiaFactory, "Razorpay");
        service.completeOrder(1000.0); // Processing payment of 1000.0 using Razorpay
    }

    {
        CheckoutService service(usFactory, "PayPal");
        service.completeOrder(2000.0); // Processing payment of 2000.0 using PayPal
    }

    return 0;
}
