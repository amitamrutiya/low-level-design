#include <iostream>
#include <memory>

// Interface provided for classes to implement different recommendation strategies
class RecommendationStrategy {
public:
    virtual void getRecommendations() = 0;
    virtual ~RecommendationStrategy() = default;
};

// Class implementing recommendations based on recently added
class RecentlyAdded : public RecommendationStrategy {
public:
    void getRecommendations() override {
        std::cout << "Showing recently added content..." << std::endl;
    }
};

// Class implementing recommendations based on trending now
class TrendingNow : public RecommendationStrategy {
public:
    void getRecommendations() override {
        std::cout << "Showing trending content..." << std::endl;
    }
};

// Class implementing recommendations based on Genre
class GenreBased : public RecommendationStrategy {
public:
    void getRecommendations() override {
        std::cout << "Showing content based on your favorite genres..." << std::endl;
    }
};

// Class implementing the Recommendation Engine (High-level module)
class RecommendationEngine {
private:
    std::shared_ptr<RecommendationStrategy> strategy;

public:
    RecommendationEngine(std::shared_ptr<RecommendationStrategy> strat) 
        : strategy(strat) {}

    void recommend() {
        strategy->getRecommendations();
    }
};

int main() {
    auto strategy = std::make_shared<TrendingNow>(); // could also be RecentlyAdded or GenreBased
    RecommendationEngine engine(strategy);
    engine.recommend();
    
    // Can easily switch strategies
    engine = RecommendationEngine(std::make_shared<RecentlyAdded>());
    engine.recommend();
    
    return 0;
}
