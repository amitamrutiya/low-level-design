abstract class SupportHandler {
    protected SupportHandler nextHandler;

    public void setNextHandler(SupportHandler nextHandler) {
        this.nextHandler = nextHandler;
    }

    public abstract void handleRequest(String requestType);
}

class GeneralSupportHandler extends SupportHandler {
    @Override
    public void handleRequest(String requestType) {
        if (requestType.equals("General Inquiry")) {
            System.out.println("Handling general inquiry.");
        } else if (nextHandler != null) {
            nextHandler.handleRequest(requestType);
        }
    }
}

class TechnicalSupportHandler extends SupportHandler {
    @Override
    public void handleRequest(String requestType) {
        if (requestType.equals("Technical Issue")) {
            System.out.println("Handling technical issue.");
        } else if (nextHandler != null) {
            nextHandler.handleRequest(requestType);
        }
    }
}

class RefundSupportHandler extends SupportHandler {
    @Override
    public void handleRequest(String requestType) {
        if (requestType.equals("Refund Request")) {
            System.out.println("Handling refund request.");
        } else if (nextHandler != null) {
            nextHandler.handleRequest(requestType);
        }
    }
}

class DeliveryComplaintHandler extends SupportHandler {
    @Override
    public void handleRequest(String requestType) {
        if (requestType.equals("Delivery Complaint")) {
            System.out.println("Handling delivery complaint.");
        } else if (nextHandler != null) {
            nextHandler.handleRequest(requestType);
        } else {
            System.out.println("Request not recognized.");
        }
    }
}

public class Main {
    public static void main(String[] args) {
        // Create handlers
        SupportHandler generalSupport = new GeneralSupportHandler();
        SupportHandler technicalSupport = new TechnicalSupportHandler();
        SupportHandler refundSupport = new RefundSupportHandler();
        SupportHandler deliveryComplaint = new DeliveryComplaintHandler();

        // Set up the chain of responsibility general -> technical -> refund -> delivery
        generalSupport.setNextHandler(technicalSupport);
        technicalSupport.setNextHandler(refundSupport);
        refundSupport.setNextHandler(deliveryComplaint);

        // Test the chain with different requests
        generalSupport.handleRequest("Refund Request");
        generalSupport.handleRequest("Delivery Complaint");
        generalSupport.handleRequest("General Inquiry");
        generalSupport.handleRequest("Technical Issue");
        generalSupport.handleRequest("Unknown Request");
    }
}
