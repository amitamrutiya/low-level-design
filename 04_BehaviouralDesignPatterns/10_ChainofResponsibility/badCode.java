// In a customer support system, we have different levels of support agents.
// General inquiries are handled by a general support agent, while technical issues are escalated to a technical support agent.
// Refund requests are handled by a refund support agent.
// Technical issues can be escalated to a senior technical support agent if the initial agent cannot resolve them.
// Complains about delivery

class SupportService {
    public void handleRequest(String request) {
        if (request.equals("General Inquiry")) {
            System.out.println("Handling general inquiry.");
        } else if (request.equals("Technical Issue")) {
            System.out.println("Handling technical issue.");
        } else if (request.equals("Refund Request")) {
            System.out.println("Handling refund request.");
        } else if (request.equals("Delivery Complaint")) {
            System.out.println("Handling delivery complaint.");
        } else {
            System.out.println("Request not recognized.");
        }
    }
}

// violates the Open/Closed Principle
// monolithic structure
// not flexible or scalable