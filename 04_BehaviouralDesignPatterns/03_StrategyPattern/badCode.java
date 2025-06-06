class RideMatchingServic {
    public void matchRider(String riderLocation, String matchingType) {
        if (matchingType.equals("nearest")) {
            // Logic to find the nearest driver
            System.out.println("Matching rider at " + riderLocation + " with nearest driver.");
        } else if (matchingType.equals("fastest")) {
            // Logic to find the fastest driver
            System.out.println("Matching rider at " + riderLocation + " with fastest driver.");
        } else if (matchingType.equals("cheapest")) {
            // Logic to find the cheapest driver
            System.out.println("Matching rider at " + riderLocation + " with cheapest driver.");
        } else {
            System.out.println("Invalid matching type.");
        }
    }
}

public class badCode {
    public static void main(String[] args) {
        RideMatchingServic rideMatchingService = new RideMatchingServic();
        rideMatchingService.matchRider("Downtown", "nearest");
        rideMatchingService.matchRider("Uptown", "fastest");
        rideMatchingService.matchRider("Suburbs", "cheapest");
        rideMatchingService.matchRider("City Center", "luxury"); // Invalid type
    }
}