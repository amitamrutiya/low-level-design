class JudgeAnalytics {
    private int run = 0;
    private int submit = 0;

    public void incrementRun() {
        run++;
    }

    public void incrementSubmit() {
        submit++;
    }

    public int getRun() {
        return run;
    }

    public int getSubmit() {
        return submit;
    }


}

public class badCode {
    public static void main(String[] args) {
        JudgeAnalytics analytics = new JudgeAnalytics();
        analytics.incrementRun();
        analytics.incrementSubmit();
        System.out.println("Runs: " + analytics.getRun());
        System.out.println("Submissions: " + analytics.getSubmit());

        // Resetting the analytics
       JudgeAnalytics analytics2 = new JudgeAnalytics();
        System.out.println("After reset - Runs: " + analytics2.getRun());
        System.out.println("After reset - Submissions: " + analytics2.getSubmit());
    }
}