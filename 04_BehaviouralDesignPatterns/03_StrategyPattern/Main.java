interface RideMatchingStrategy {
    void matchRider(String riderLocation);
}

class NearestDriverStrategy implements RideMatchingStrategy {
    @Override
    public void matchRider(String riderLocation) {
        System.out.println("Matching rider at " + riderLocation + " with nearest driver.");
    }
}

class FastestDriverStrategy implements RideMatchingStrategy {
    @Override
    public void matchRider(String riderLocation) {
        System.out.println("Matching rider at " + riderLocation + " with fastest driver.");
    }
}

class CheapestDriverStrategy implements RideMatchingStrategy {
    @Override
    public void matchRider(String riderLocation) {
        System.out.println("Matching rider at " + riderLocation + " with cheapest driver.");
    }
}

class RideMatchingService {
    private RideMatchingStrategy matchingStrategy;

    public void setMatchingStrategy(RideMatchingStrategy strategy) {
        this.matchingStrategy = strategy;
    }

    public void matchRider(String riderLocation) {
        if (matchingStrategy == null) {
            System.out.println("Please set a matching strategy first.");
            return;
        }
        matchingStrategy.matchRider(riderLocation);
    }
}

public class Main {
    public static void main(String[] args) {
        RideMatchingService rideMatchingService = new RideMatchingService();

        // Using nearest driver strategy
        rideMatchingService.setMatchingStrategy(new NearestDriverStrategy());
        rideMatchingService.matchRider("Downtown");

        // Using fastest driver strategy
        rideMatchingService.setMatchingStrategy(new FastestDriverStrategy());
        rideMatchingService.matchRider("Uptown");

        // Using cheapest driver strategy
        rideMatchingService.setMatchingStrategy(new CheapestDriverStrategy());
        rideMatchingService.matchRider("Suburbs");
    }
}