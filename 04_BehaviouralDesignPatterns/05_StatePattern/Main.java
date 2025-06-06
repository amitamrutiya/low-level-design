interface OrderState {
    void nextState(OrderContext context);

    void cancelOrder(OrderContext context);

    String getStateName();
}

class OrderPlacedState implements OrderState {
    @Override
    public void nextState(OrderContext context) {
        System.out.println("Order is now being processed.");
        context.setState(new OrderProcessingState());
    }

    @Override
    public void cancelOrder(OrderContext context) {
        System.out.println("Order has been cancelled.");
        context.setState(new OrderCancelledState());
    }

    @Override
    public String getStateName() {
        return "Order Placed";
    }
}

class OrderProcessingState implements OrderState {
    @Override
    public void nextState(OrderContext context) {
        System.out.println("Order is now being prepared.");
        context.setState(new OrderPreparedState());
    }

    @Override
    public void cancelOrder(OrderContext context) {
        System.out.println("Order cannot be cancelled while processing.");
    }

    @Override
    public String getStateName() {
        return "Order Processing";
    }
}

class OrderPreparedState implements OrderState {
    @Override
    public void nextState(OrderContext context) {
        System.out.println("Order is now ready for delivery.");
        context.setState(new OrderReadyForDeliveryState());
    }

    @Override
    public void cancelOrder(OrderContext context) {
        System.out.println("Order cannot be cancelled after preparation.");
    }

    @Override
    public String getStateName() {
        return "Order Prepared";
    }
}

class OrderReadyForDeliveryState implements OrderState {
    @Override
    public void nextState(OrderContext context) {
        System.out.println("Order is out for delivery.");
        context.setState(new OrderOutForDeliveryState());
    }

    @Override
    public void cancelOrder(OrderContext context) {
        System.out.println("Order cannot be cancelled after being prepared for delivery.");
    }

    @Override
    public String getStateName() {
        return "Order Ready for Delivery";
    }
}

class OrderOutForDeliveryState implements OrderState {
    @Override
    public void nextState(OrderContext context) {
        System.out.println("Order has been delivered.");
        context.setState(new OrderDeliveredState());
    }

    @Override
    public void cancelOrder(OrderContext context) {
        System.out.println("Order cannot be cancelled after being out for delivery.");
    }

    @Override
    public String getStateName() {
        return "Order Out for Delivery";
    }
}

class OrderDeliveredState implements OrderState {
    @Override
    public void nextState(OrderContext context) {
        System.out.println("Order is already delivered. No further state transitions available.");
    }

    @Override
    public void cancelOrder(OrderContext context) {
        System.out.println("Order cannot be cancelled after delivery.");
    }

    @Override
    public String getStateName() {
        return "Order Delivered";
    }
}

class OrderCancelledState implements OrderState {
    @Override
    public void nextState(OrderContext context) {
        System.out.println("Order is cancelled. No further state transitions available.");
    }

    @Override
    public void cancelOrder(OrderContext context) {
        System.out.println("Order is already cancelled.");
    }

    @Override
    public String getStateName() {
        return "Order Cancelled";
    }
}

class OrderContext {
    private OrderState state;

    public OrderContext() {
        this.state = new OrderPlacedState();
    }

    public void setState(OrderState state) {
        this.state = state;
    }

    public void nextState() {
        state.nextState(this);
    }

    public void cancelOrder() {
        state.cancelOrder(this);
    }

    public String getStateName() {
        return state.getStateName();
    }
}

public class Main {
    public static void main(String[] args) {
        OrderContext order = new OrderContext();

        System.out.println("Current State: " + order.getStateName());
        order.nextState(); // Move to processing
        System.out.println("Current State: " + order.getStateName());

        order.cancelOrder(); // Attempt to cancel while processing
        System.out.println("Current State: " + order.getStateName());

        order.nextState(); // Move to prepared
        System.out.println("Current State: " + order.getStateName());

        order.nextState(); // Move to ready for delivery
        System.out.println("Current State: " + order.getStateName());

        order.nextState(); // Move to out for delivery
        System.out.println("Current State: " + order.getStateName());

        order.nextState(); // Move to delivered
        System.out.println("Current State: " + order.getStateName());

        order.cancelOrder(); // Attempt to cancel after delivery
        System.out.println("Current State: " + order.getStateName());
    }
}