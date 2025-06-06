#include <iostream>
#include <string>
#include <memory>

// Support request class to hold request details
class SupportRequest {
public:
    enum class Type {
        GENERAL_INQUIRY,
        TECHNICAL_ISSUE,
        REFUND_REQUEST,
        DELIVERY_COMPLAINT
    };

    enum class Priority {
        LOW,
        MEDIUM,
        HIGH,
        URGENT
    };

private:
    Type type;
    Priority priority;
    std::string description;
    bool resolved;

public:
    SupportRequest(Type type, Priority priority, const std::string& description)
        : type(type), priority(priority), description(description), resolved(false) {}

    Type getType() const { return type; }
    Priority getPriority() const { return priority; }
    const std::string& getDescription() const { return description; }
    bool isResolved() const { return resolved; }
    void setResolved(bool value) { resolved = value; }
};

// Handler interface
class SupportHandler {
protected:
    std::shared_ptr<SupportHandler> nextHandler;
    std::string handlerName;

public:
    explicit SupportHandler(std::string name) : handlerName(std::move(name)) {}

    void setNext(std::shared_ptr<SupportHandler> handler) {
        nextHandler = handler;
    }

    virtual bool canHandle(const SupportRequest& request) const = 0;
    
    virtual void handle(SupportRequest& request) {
        if (canHandle(request)) {
            std::cout << handlerName << " is handling the request: " << request.getDescription() << std::endl;
            processRequest(request);
        } else if (nextHandler) {
            std::cout << handlerName << " passing request to next handler." << std::endl;
            nextHandler->handle(request);
        } else {
            std::cout << "No handler available for this request." << std::endl;
        }
    }

    virtual void processRequest(SupportRequest& request) = 0;
    virtual ~SupportHandler() = default;
};

// Concrete handlers
class GeneralSupportHandler : public SupportHandler {
public:
    GeneralSupportHandler() : SupportHandler("General Support") {}

    bool canHandle(const SupportRequest& request) const override {
        return request.getType() == SupportRequest::Type::GENERAL_INQUIRY &&
               request.getPriority() == SupportRequest::Priority::LOW;
    }

    void processRequest(SupportRequest& request) override {
        std::cout << "Providing general information and assistance." << std::endl;
        request.setResolved(true);
    }
};

class TechnicalSupportHandler : public SupportHandler {
public:
    TechnicalSupportHandler() : SupportHandler("Technical Support") {}

    bool canHandle(const SupportRequest& request) const override {
        return request.getType() == SupportRequest::Type::TECHNICAL_ISSUE &&
               request.getPriority() != SupportRequest::Priority::URGENT;
    }

    void processRequest(SupportRequest& request) override {
        if (request.getPriority() == SupportRequest::Priority::HIGH) {
            std::cout << "Attempting to resolve complex technical issue..." << std::endl;
            // Simulate complex issue that needs escalation
            if (nextHandler) {
                nextHandler->handle(request);
                return;
            }
        }
        std::cout << "Resolving technical issue with standard procedures." << std::endl;
        request.setResolved(true);
    }
};

class SeniorTechnicalSupportHandler : public SupportHandler {
public:
    SeniorTechnicalSupportHandler() : SupportHandler("Senior Technical Support") {}

    bool canHandle(const SupportRequest& request) const override {
        return request.getType() == SupportRequest::Type::TECHNICAL_ISSUE;
    }

    void processRequest(SupportRequest& request) override {
        std::cout << "Senior technical support resolving complex issue..." << std::endl;
        request.setResolved(true);
    }
};

class RefundSupportHandler : public SupportHandler {
public:
    RefundSupportHandler() : SupportHandler("Refund Support") {}

    bool canHandle(const SupportRequest& request) const override {
        return request.getType() == SupportRequest::Type::REFUND_REQUEST;
    }

    void processRequest(SupportRequest& request) override {
        std::cout << "Processing refund request..." << std::endl;
        request.setResolved(true);
    }
};

class DeliverySupportHandler : public SupportHandler {
public:
    DeliverySupportHandler() : SupportHandler("Delivery Support") {}

    bool canHandle(const SupportRequest& request) const override {
        return request.getType() == SupportRequest::Type::DELIVERY_COMPLAINT;
    }

    void processRequest(SupportRequest& request) override {
        std::cout << "Investigating delivery complaint..." << std::endl;
        request.setResolved(true);
    }
};

// Support chain builder
class SupportChain {
private:
    std::shared_ptr<SupportHandler> firstHandler;
    std::shared_ptr<SupportHandler> lastHandler;

public:
    void addHandler(std::shared_ptr<SupportHandler> handler) {
        if (!firstHandler) {
            firstHandler = handler;
            lastHandler = handler;
        } else {
            lastHandler->setNext(handler);
            lastHandler = handler;
        }
    }

    void handleRequest(SupportRequest& request) {
        if (firstHandler) {
            firstHandler->handle(request);
        } else {
            std::cout << "Support chain is empty!" << std::endl;
        }
    }
};

int main() {
    // Create the support chain
    SupportChain supportChain;
    
    // Add handlers in order of escalation
    supportChain.addHandler(std::make_shared<GeneralSupportHandler>());
    supportChain.addHandler(std::make_shared<TechnicalSupportHandler>());
    supportChain.addHandler(std::make_shared<SeniorTechnicalSupportHandler>());
    supportChain.addHandler(std::make_shared<RefundSupportHandler>());
    supportChain.addHandler(std::make_shared<DeliverySupportHandler>());

    // Test different types of requests
    std::cout << "=== Testing General Inquiry ===" << std::endl;
    SupportRequest generalRequest(
        SupportRequest::Type::GENERAL_INQUIRY,
        SupportRequest::Priority::LOW,
        "How do I reset my password?"
    );
    supportChain.handleRequest(generalRequest);
    std::cout << std::endl;

    std::cout << "=== Testing Technical Issue ===" << std::endl;
    SupportRequest technicalRequest(
        SupportRequest::Type::TECHNICAL_ISSUE,
        SupportRequest::Priority::HIGH,
        "Application keeps crashing"
    );
    supportChain.handleRequest(technicalRequest);
    std::cout << std::endl;

    std::cout << "=== Testing Refund Request ===" << std::endl;
    SupportRequest refundRequest(
        SupportRequest::Type::REFUND_REQUEST,
        SupportRequest::Priority::MEDIUM,
        "Wrong item delivered"
    );
    supportChain.handleRequest(refundRequest);
    std::cout << std::endl;

    std::cout << "=== Testing Delivery Complaint ===" << std::endl;
    SupportRequest deliveryRequest(
        SupportRequest::Type::DELIVERY_COMPLAINT,
        SupportRequest::Priority::HIGH,
        "Package not received"
    );
    supportChain.handleRequest(deliveryRequest);

    return 0;
}