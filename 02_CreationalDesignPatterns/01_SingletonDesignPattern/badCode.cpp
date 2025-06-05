#include <iostream>

using namespace std;

class JudgeAnalytics {
private:
    int run = 0;
    int submit = 0;

public:
    void incrementRun() {
        run++;
    }

    void incrementSubmit() {
        submit++;
    }

    int getRun() {
        return run;
    }

    int getSubmit() {
        return submit;
    }
};

int main() {
    JudgeAnalytics analytics;
    analytics.incrementRun();
    analytics.incrementSubmit();
    cout << "Runs: " << analytics.getRun() << endl;
    cout << "Submissions: " << analytics.getSubmit() << endl;

    // Resetting the analytics
    JudgeAnalytics analytics2;
    cout << "After reset - Runs: " << analytics2.getRun() << endl;
    cout << "After reset - Submissions: " << analytics2.getSubmit() << endl;

    return 0;
}
