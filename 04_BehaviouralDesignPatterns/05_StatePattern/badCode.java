class Order {
    private String state;

    public Order() {
        this.state = "ORDER_PLACED";
    }

    public void cancleOrder() {
        if (state.equals("ORDER_PLACED") || state.equals("PREPARING")) {
            System.out.println("Cancelling order");
            state = "ORDER_CANCELLED";
        } else {
            System.out.println("Cannot cancel order in current state: " + state);
        }
    }

    public void nextState() {
        switch (state) {
            case "ORDER_PLACED":
                System.out.println("Order is now being prepared");
                state = "PREPARING";
                break;
            case "PREPARING":
                System.out.println("Order is now ready for delivery");
                state = "READY_FOR_DELIVERY";
                break;
            case "READY_FOR_DELIVERY":
                System.out.println("Order is out for delivery");
                state = "OUT_FOR_DELIVERY";
                break;
            case "OUT_FOR_DELIVERY":
                System.out.println("Order has been delivered");
                state = "DELIVERED";
                break;
            default:
                System.out.println("No further state transitions available from: " + state);
        }
    }

    public String getState() {
        return state;
    }
}