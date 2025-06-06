#include <iostream>
#include <string>

// In a customer support system, we have different levels of support agents.
// General inquiries are handled by a general support agent, while technical issues are escalated to a technical support agent.
// Refund requests are handled by a refund support agent.
// Technical issues can be escalated to a senior technical support agent if the initial agent cannot resolve them.

class SupportService {
public:
    void handleRequest(const std::string& request) {
        if (request == "General Inquiry") {
            std::cout << "Handling general inquiry." << std::endl;
            // Logic for handling general inquiries
            std::cout << "Support agent providing basic information and assistance." << std::endl;
        }
        else if (request == "Technical Issue") {
            std::cout << "Handling technical issue." << std::endl;
            // Logic for handling technical issues
            std::cout << "Technical support agent troubleshooting the problem." << std::endl;

            // Trying to resolve at first level
            bool resolved = false;
            if (!resolved) {
                std::cout << "Escalating to senior technical support." << std::endl;
                // Senior technical support logic
                std::cout << "Senior technical support agent handling complex issue." << std::endl;
            }
        }
        else if (request == "Refund Request") {
            std::cout << "Handling refund request." << std::endl;
            // Logic for handling refund requests
            std::cout << "Refund department processing the request." << std::endl;
        }
        else if (request == "Delivery Complaint") {
            std::cout << "Handling delivery complaint." << std::endl;
            // Logic for handling delivery complaints
            std::cout << "Delivery department investigating the issue." << std::endl;
        }
        else {
            std::cout << "Request not recognized." << std::endl;
        }
    }
};

int main() {
    SupportService support;

    // Testing different types of requests
    support.handleRequest("General Inquiry");
    std::cout << "\n";
    
    support.handleRequest("Technical Issue");
    std::cout << "\n";
    
    support.handleRequest("Refund Request");
    std::cout << "\n";
    
    support.handleRequest("Delivery Complaint");
    std::cout << "\n";
    
    support.handleRequest("Invalid Request");

    return 0;
}

// Problems with this approach:
// 1. Violates the Open/Closed Principle - need to modify existing code to add new request types
// 2. Monolithic structure - all handling logic is in one place
// 3. Not flexible or scalable - hard to add new types of requests or modify handling logic
// 4. Poor separation of concerns - different types of support mixed together
// 5. Difficult to maintain - changes to one type affect the entire class
// 6. No clear responsibility chain - handling is immediate and direct
// 7. Hard to modify the flow of requests
// 8. No ability to dynamically change handlers