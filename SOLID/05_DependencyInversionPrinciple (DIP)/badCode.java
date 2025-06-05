// Class implementing the recommendations based on recently added
class RecentlyAdded {
    // Method to get the recommendations
    public void getRecommendations() {
        System.out.println("Showing recently added content...");
    }
}

class TrendingNow {
    // Method to get the recommendations
    public void getTrendingRecommendations() {
        System.out.println("Showing trending content...");
    }
}

class GenreBased {
    // Method to get the recommendations
    public void getGenraRecommendations() {
        System.out.println("Showing content based on your favorite genres...");
    }
}

// Class implementing the overall Recommendation Engine
class RecommendationEngine {
    private RecentlyAdded recommender = new RecentlyAdded();
    private TrendingNow trendingRecommender = new TrendingNow();
    private GenreBased genreRecommender = new GenreBased();

    public void recommend() {
        recommender.getRecommendations();
    }
    public void recommendTrending() {
        trendingRecommender.getTrendingRecommendations();
    }
    public void recommendGenre() {
        genreRecommender.getGenraRecommendations();
    }
    

}
