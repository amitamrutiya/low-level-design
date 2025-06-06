#include <iostream>
#include <string>
#include <memory>

// Strategy interface
class MatchingStrategy {
public:
    virtual void matchRider(const std::string& riderLocation) = 0;
    virtual ~MatchingStrategy() = default;
};

// Concrete strategies
class NearestDriverStrategy : public MatchingStrategy {
public:
    void matchRider(const std::string& riderLocation) override {
        std::cout << "Matching rider at " << riderLocation << " with nearest driver." << std::endl;
    }
};

class FastestDriverStrategy : public MatchingStrategy {
public:
    void matchRider(const std::string& riderLocation) override {
        std::cout << "Matching rider at " << riderLocation << " with fastest driver." << std::endl;
    }
};

class CheapestDriverStrategy : public MatchingStrategy {
public:
    void matchRider(const std::string& riderLocation) override {
        std::cout << "Matching rider at " << riderLocation << " with cheapest driver." << std::endl;
    }
};

// Context
class RideMatchingService {
private:
    std::unique_ptr<MatchingStrategy> strategy;

public:
    void setMatchingStrategy(std::unique_ptr<MatchingStrategy> newStrategy) {
        strategy = std::move(newStrategy);
    }

    void matchRider(const std::string& riderLocation) {
        if (strategy) {
            strategy->matchRider(riderLocation);
        } else {
            std::cout << "No matching strategy set!" << std::endl;
        }
    }
};

int main() {
    RideMatchingService rideMatchingService;

    // Using nearest driver strategy
    rideMatchingService.setMatchingStrategy(std::make_unique<NearestDriverStrategy>());
    rideMatchingService.matchRider("Downtown");

    // Switch to fastest driver strategy
    rideMatchingService.setMatchingStrategy(std::make_unique<FastestDriverStrategy>());
    rideMatchingService.matchRider("Uptown");

    // Switch to cheapest driver strategy
    rideMatchingService.setMatchingStrategy(std::make_unique<CheapestDriverStrategy>());
    rideMatchingService.matchRider("Suburbs");

    return 0;
}