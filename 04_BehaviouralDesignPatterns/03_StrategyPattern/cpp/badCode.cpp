#include <iostream>
#include <string>

class RideMatchingService {
public:
    void matchRider(const std::string& riderLocation, const std::string& matchingType) {
        if (matchingType == "nearest") {
            // Logic to find the nearest driver
            std::cout << "Matching rider at " << riderLocation << " with nearest driver." << std::endl;
        }
        else if (matchingType == "fastest") {
            // Logic to find the fastest driver
            std::cout << "Matching rider at " << riderLocation << " with fastest driver." << std::endl;
        }
        else if (matchingType == "cheapest") {
            // Logic to find the cheapest driver
            std::cout << "Matching rider at " << riderLocation << " with cheapest driver." << std::endl;
        }
        else {
            std::cout << "Invalid matching type." << std::endl;
        }
    }
};

int main() {
    RideMatchingService rideMatchingService;
    rideMatchingService.matchRider("Downtown", "nearest");
    rideMatchingService.matchRider("Uptown", "fastest");
    rideMatchingService.matchRider("Suburbs", "cheapest");
    rideMatchingService.matchRider("City Center", "luxury"); // Invalid type
    
    return 0;
}