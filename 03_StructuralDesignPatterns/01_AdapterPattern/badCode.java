interface PaymentGateway {
    void pay(String orderId, double amount);
}

class PayUGateway implements PaymentGateway {
    @Override
    public void pay(String orderId, double amount) {
        System.out.println("Processing payment of " + amount + " for order " + orderId + " using PayU.");
    }
}

class RazorpayAPI {
    public void makePayment(String orderId, double amount) {
        System.out.println("Processing payment of " + amount + " for order " + orderId + " using Razorpay.");
    }
}

class CheckoutService {
    private PaymentGateway paymentGateway;

    public CheckoutService(PaymentGateway paymentGateway) {
        this.paymentGateway = paymentGateway;
    }

    public void processOrder(String orderId, double amount) {
        paymentGateway.pay(orderId, amount);
    }
}

public class badCode {
    public static void main(String[] args) {
        // This is a bad implementation from a performance and maintainability
        // perspective:
        // 1. Performance Issues:
        // - Creates new CheckoutService instances for each order
        // - Initializes payment gateway repeatedly
        // - Inefficient when processing many orders
        // 2. Maintainability Issues:
        // - Any changes to payment gateway require updating CheckoutService constructor
        // - No way to change payment gateway dynamically without modifying code

        // Solution using Adapter Pattern would:
        // - Allow dynamic switching of payment gateways
        // - Improve performance by reusing existing services
        // - Make payment processing more flexible and maintainable

        PaymentGateway payUGateway = new PayUGateway();
        CheckoutService checkoutService = new CheckoutService(payUGateway);

        checkoutService.processOrder("12345", 250.75);
    }
}