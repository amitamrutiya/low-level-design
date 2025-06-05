#include <iostream>
#include <memory>

// Class implementing the recommendations based on recently added
class RecentlyAdded {
public:
    void getRecommendations() {
        std::cout << "Showing recently added content..." << std::endl;
    }
};

class TrendingNow {
public:
    void getTrendingRecommendations() {
        std::cout << "Showing trending content..." << std::endl;
    }
};

class GenreBased {
public:
    void getGenreRecommendations() {
        std::cout << "Showing content based on your favorite genres..." << std::endl;
    }
};

// Class implementing the overall Recommendation Engine
class RecommendationEngine {
private:
    RecentlyAdded recommender;
    TrendingNow trendingRecommender;
    GenreBased genreRecommender;

public:
    void recommend() {
        recommender.getRecommendations();
    }
    
    void recommendTrending() {
        trendingRecommender.getTrendingRecommendations();
    }
    
    void recommendGenre() {
        genreRecommender.getGenreRecommendations();
    }
};

int main() {
    RecommendationEngine engine;
    engine.recommend();
    engine.recommendTrending();
    engine.recommendGenre();
    return 0;
}
