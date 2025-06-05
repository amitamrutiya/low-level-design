#include <iostream>
#include <memory>

using namespace std;

// Class implementing the recommendations based on recently added
class RecentlyAdded {
public:
    void getRecommendations() {
        cout << "Showing recently added content..." << endl;
    }
};

class TrendingNow {
public:
    void getTrendingRecommendations() {
        cout << "Showing trending content..." << endl;
    }
};

class GenreBased {
public:
    void getGenreRecommendations() {
        cout << "Showing content based on your favorite genres..." << endl;
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
