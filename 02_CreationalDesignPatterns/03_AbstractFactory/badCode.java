interface PaymentGateway {
    void processPayment(double amount);
}

class RazorpayGateway implements PaymentGateway {
    @Override
    public void processPayment(double amount) {
        System.out.println("Processing payment of " + amount + " using Razorpay");
    }
}

class PayUGateway implements PaymentGateway {
    @Override
    public void processPayment(double amount) {
        System.out.println("Processing payment of " + amount + " using PayU");
    }
}

interface Invoice {
    void generateInvoice();
}

class GSTInvoice implements Invoice {
    @Override
    public void generateInvoice() {
        System.out.println("Generating GST Invoice for India");
    }
}

// VIOLATION 1: Abstract Factory Pattern Violations:
// 1. Missing abstract factory interface that defines contract for creating
// payment gateways and invoices
// 2. Factory implementation is tightly coupled with concrete classes
// 3. Static methods prevent flexibility and make testing difficult
// 4. No separation between factory interface and implementation
class IndiaFactory {
    public static PaymentGateway createPaymentGateway(String type) {
        if (type.equals("Razorpay")) {
            return new RazorpayGateway();
        } else if (type.equals("PayU")) {
            return new PayUGateway();
        } else {
            throw new IllegalArgumentException("Unknown payment gateway: " + type);
        }
    }

    public static Invoice createInvoice() {
        return new GSTInvoice();
    }
}

class CheckoutService {
    private String gatewayType;
    private String countryCode;

    public CheckoutService(String gatewayType, String countryCode) {
        this.gatewayType = gatewayType;
        this.countryCode = countryCode;
    }

    public void checkOut(double amount) {
        // VIOLATION 2: Violating Abstract Factory Pattern:
        // 1. Direct instantiation of concrete classes instead of using factory
        // 2. Hard-coded country check instead of using abstract factory
        // 3. Should use a factory provider to get the appropriate country factory
        // 4. Tight coupling with IndiaFactory implementation
        if ("INDIA".equals(countryCode)) {
            PaymentGateway paymentGateway = IndiaFactory.createPaymentGateway(gatewayType);
            paymentGateway.processPayment(amount);
            Invoice invoice = IndiaFactory.createInvoice();
            invoice.generateInvoice();
        } else {
            // VIOLATION 3: Missing implementations for other countries
            // Should have concrete factories for each country implementing the abstract
            // factory interface
        }
    }

}

public class badCode {
    public static void main(String[] args) {

    }
}