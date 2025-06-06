#include <iostream>
#include <string>

class Order {
private:
    std::string state;

public:
    Order() : state("ORDER_PLACED") {}

    void cancelOrder() {
        if (state == "ORDER_PLACED" || state == "PREPARING") {
            std::cout << "Cancelling order" << std::endl;
            state = "ORDER_CANCELLED";
        } else {
            std::cout << "Cannot cancel order in current state: " << state << std::endl;
        }
    }

    void nextState() {
        if (state == "ORDER_PLACED") {
            std::cout << "Order is now being prepared" << std::endl;
            state = "PREPARING";
        }
        else if (state == "PREPARING") {
            std::cout << "Order is now ready for delivery" << std::endl;
            state = "READY_FOR_DELIVERY";
        }
        else if (state == "READY_FOR_DELIVERY") {
            std::cout << "Order is out for delivery" << std::endl;
            state = "OUT_FOR_DELIVERY";
        }
        else if (state == "OUT_FOR_DELIVERY") {
            std::cout << "Order has been delivered" << std::endl;
            state = "DELIVERED";
        }
        else {
            std::cout << "No further state transitions available from: " << state << std::endl;
        }
    }

    std::string getState() const {
        return state;
    }
};

int main() {
    Order order;
    std::cout << "Initial state: " << order.getState() << std::endl;
    
    order.nextState();  // ORDER_PLACED -> PREPARING
    order.nextState();  // PREPARING -> READY_FOR_DELIVERY
    order.cancelOrder(); // Cannot cancel in READY_FOR_DELIVERY
    order.nextState();  // READY_FOR_DELIVERY -> OUT_FOR_DELIVERY
    order.nextState();  // OUT_FOR_DELIVERY -> DELIVERED
    order.nextState();  // No further transitions
    
    return 0;
}