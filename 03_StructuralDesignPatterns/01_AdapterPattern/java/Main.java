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

class RazorpayAdapter implements PaymentGateway {
    private RazorpayAPI razorpayAPI;

    public RazorpayAdapter() {
        this.razorpayAPI = new RazorpayAPI();
    }

    @Override
    public void pay(String orderId, double amount) {
        razorpayAPI.makePayment(orderId, amount);
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

public class Main {
    public static void main(String[] args) {

        PaymentGateway razorpayGateway = new RazorpayAdapter();
        CheckoutService checkoutService = new CheckoutService(razorpayGateway);

        checkoutService.processOrder("12345", 250.75);
    }
}