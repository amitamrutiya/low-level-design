#include <iostream>
#include <memory>
#include <string>

// Forward declaration
class Order;

// State interface
class OrderState {
public:
    virtual void nextState(Order& order) = 0;
    virtual void cancelOrder(Order& order) = 0;
    virtual std::string getStateName() const = 0;
    virtual ~OrderState() = default;
};

// Order class (Context)
class Order {
private:
    std::unique_ptr<OrderState> currentState;

public:
    Order();
    void setState(std::unique_ptr<OrderState> state);
    void nextState();
    void cancelOrder();
    std::string getState() const;
};

// Concrete states
class OrderPlacedState : public OrderState {
public:
    void nextState(Order& order) override;
    void cancelOrder(Order& order) override;
    std::string getStateName() const override {
        return "ORDER_PLACED";
    }
};

class PreparingState : public OrderState {
public:
    void nextState(Order& order) override;
    void cancelOrder(Order& order) override;
    std::string getStateName() const override {
        return "PREPARING";
    }
};

class ReadyForDeliveryState : public OrderState {
public:
    void nextState(Order& order) override;
    void cancelOrder(Order& order) override;
    std::string getStateName() const override {
        return "READY_FOR_DELIVERY";
    }
};

class OutForDeliveryState : public OrderState {
public:
    void nextState(Order& order) override;
    void cancelOrder(Order& order) override;
    std::string getStateName() const override {
        return "OUT_FOR_DELIVERY";
    }
};

class DeliveredState : public OrderState {
public:
    void nextState(Order& order) override;
    void cancelOrder(Order& order) override;
    std::string getStateName() const override {
        return "DELIVERED";
    }
};

class CancelledState : public OrderState {
public:
    void nextState(Order& order) override;
    void cancelOrder(Order& order) override;
    std::string getStateName() const override {
        return "CANCELLED";
    }
};

// Order implementation
Order::Order() {
    currentState = std::make_unique<OrderPlacedState>();
}

void Order::setState(std::unique_ptr<OrderState> state) {
    currentState = std::move(state);
}

void Order::nextState() {
    currentState->nextState(*this);
}

void Order::cancelOrder() {
    currentState->cancelOrder(*this);
}

std::string Order::getState() const {
    return currentState->getStateName();
}

// State implementations
void OrderPlacedState::nextState(Order& order) {
    std::cout << "Order is now being prepared" << std::endl;
    order.setState(std::make_unique<PreparingState>());
}

void OrderPlacedState::cancelOrder(Order& order) {
    std::cout << "Cancelling order" << std::endl;
    order.setState(std::make_unique<CancelledState>());
}

void PreparingState::nextState(Order& order) {
    std::cout << "Order is now ready for delivery" << std::endl;
    order.setState(std::make_unique<ReadyForDeliveryState>());
}

void PreparingState::cancelOrder(Order& order) {
    std::cout << "Cancelling order" << std::endl;
    order.setState(std::make_unique<CancelledState>());
}

void ReadyForDeliveryState::nextState(Order& order) {
    std::cout << "Order is out for delivery" << std::endl;
    order.setState(std::make_unique<OutForDeliveryState>());
}

void ReadyForDeliveryState::cancelOrder(Order& order) {
    std::cout << "Cannot cancel order in ready for delivery state" << std::endl;
}

void OutForDeliveryState::nextState(Order& order) {
    std::cout << "Order has been delivered" << std::endl;
    order.setState(std::make_unique<DeliveredState>());
}

void OutForDeliveryState::cancelOrder(Order& order) {
    std::cout << "Cannot cancel order in out for delivery state" << std::endl;
}

void DeliveredState::nextState(Order& order) {
    std::cout << "No further state transitions available from delivered state" << std::endl;
}

void DeliveredState::cancelOrder(Order& order) {
    std::cout << "Cannot cancel delivered order" << std::endl;
}

void CancelledState::nextState(Order& order) {
    std::cout << "Cannot transition from cancelled state" << std::endl;
}

void CancelledState::cancelOrder(Order& order) {
    std::cout << "Order is already cancelled" << std::endl;
}

int main() {
    Order order;
    std::cout << "Initial state: " << order.getState() << std::endl;
    
    order.nextState();  // ORDER_PLACED -> PREPARING
    order.nextState();  // PREPARING -> READY_FOR_DELIVERY
    order.cancelOrder(); // Cannot cancel in READY_FOR_DELIVERY
    order.nextState();  // READY_FOR_DELIVERY -> OUT_FOR_DELIVERY
    order.nextState();  // OUT_FOR_DELIVERY -> DELIVERED
    order.nextState();  // No further transitions
    order.cancelOrder(); // Cannot cancel delivered order

    Order order2;
    std::cout << "\nNew order - Initial state: " << order2.getState() << std::endl;
    order2.cancelOrder(); // Can cancel in ORDER_PLACED state
    order2.nextState();  // Cannot transition from cancelled state
    
    return 0;
}