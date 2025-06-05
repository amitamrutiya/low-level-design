
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

class PaypalGateway implements PaymentGateway {
    @Override
    public void processPayment(double amount) {
        System.out.println("Processing payment of " + amount + " using PayPal");
    }
}

class StripeGateway implements PaymentGateway {
    @Override
    public void processPayment(double amount) {
        System.out.println("Processing payment of " + amount + " using Stripe");
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

interface RegionFactory {
    PaymentGateway createPaymentGateway(String gateWayType);

    Invoice createInvoice();
}

class IndiaFactory implements RegionFactory {
    @Override
    public PaymentGateway createPaymentGateway(String type) {
        if (type.equals("Razorpay")) {
            return new RazorpayGateway();
        } else if (type.equals("PayU")) {
            return new PayUGateway();
        } else {
            throw new IllegalArgumentException("Unknown payment gateway: " + type);
        }
    }

    @Override
    public Invoice createInvoice() {
        return new GSTInvoice();
    }
}

class USFactory implements RegionFactory {
    @Override
    public PaymentGateway createPaymentGateway(String type) {
        if (type.equals("PayPal")) {
            return new PaypalGateway();
        } else if (type.equals("Stripe")) {
            return new StripeGateway();
        } else {
            throw new IllegalArgumentException("Unknown payment gateway: " + type);
        }
    }

    @Override
    public Invoice createInvoice() {
        // US-specific invoice implementation can be added here
        return null; // Placeholder for simplicity
    }
}

class CheckoutService {
    private PaymentGateway paymentGateway;
    private Invoice invoice;
    private String gatewayType;

    public CheckoutService(RegionFactory factory, String gatewayType) {
        this.gatewayType = gatewayType;
        this.paymentGateway = factory.createPaymentGateway(gatewayType);
        this.invoice = factory.createInvoice();
    }

    public void completeOrder(double amount) {
        paymentGateway.processPayment(amount);
        invoice.generateInvoice();
    }

}

public class Main {
    public static void main(String[] args) {
        CheckoutService service = new CheckoutService(new IndiaFactory(), "Razorpay");
        service.completeOrder(1000.0); // Processing payment of 1000.0 using Razorpay
        service = new CheckoutService(new USFactory(), "PayPal");
        service.completeOrder(2000.0); // Processing payment of 2000.0 using PayPal
    }
}