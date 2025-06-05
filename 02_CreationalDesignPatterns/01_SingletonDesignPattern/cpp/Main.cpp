#include <iostream>

using namespace std;

// Thread-safe Singleton Design Pattern Example with eager loading
class JudgeAnalytics {
private:
    static JudgeAnalytics* instance;
    int run = 0;
    int submit = 0;

    // Private constructor to prevent instantiation
    JudgeAnalytics() {}

public:
    // Prevent copy construction and assignment
    JudgeAnalytics(const JudgeAnalytics&) = delete;
    JudgeAnalytics& operator=(const JudgeAnalytics&) = delete;

    static JudgeAnalytics* getInstance() {
        return instance;
    }

    void incrementRun() {
        run++;
    }

    void incrementSubmit() {
        submit++;
    }

    int getRun() const {
        return run;
    }

    int getSubmit() const {
        return submit;
    }
};

// Initialize the static member
JudgeAnalytics* JudgeAnalytics::instance = new JudgeAnalytics();

int main() {
    // Get the singleton instance
    JudgeAnalytics* analytics1 = JudgeAnalytics::getInstance();
    JudgeAnalytics* analytics2 = JudgeAnalytics::getInstance();

    analytics1->incrementRun();
    analytics1->incrementSubmit();

    cout << "Analytics Instance 1 - Runs: " << analytics1->getRun() << endl;
    cout << "Analytics Instance 2 - Runs: " << analytics2->getRun() << endl;
    cout << "Are instances same? " << (analytics1 == analytics2 ? "Yes" : "No") << endl;

    return 0;
}
