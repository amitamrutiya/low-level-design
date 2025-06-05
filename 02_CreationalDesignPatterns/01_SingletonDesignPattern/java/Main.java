// Thread-safe Singleton Design Pattern Example with eager loading
class JudgeAnalytics {
    private static final JudgeAnalytics instance = new JudgeAnalytics();

    private JudgeAnalytics() {
        // Private constructor to prevent instantiation
    }

    public static JudgeAnalytics getInstance() {
        return instance;
    }
}

// Not Thread-safe Singleton Design Pattern Example with lazy loading
// class JudgeAnalytics {
//     private static JudgeAnalytics analytics;

//     private JudgeAnalytics() {
//         // Private constructor to prevent instantiation
//     }

//     public static JudgeAnalytics getInstance() {
//         if (analytics == null) {
//             analytics = new JudgeAnalytics();
//         }
//         return analytics;
//     }
// }

// Thread-safe Singleton Design Pattern Example with lazy loading but it is not efficient 
// class JudgeAnalytics {
//     private static JudgeAnalytics analytics;

//     private JudgeAnalytics() {
//         // Private constructor to prevent instantiation
//     }

//     public static synchronized JudgeAnalytics getInstance() {
//         if (analytics == null) {
//             analytics = new JudgeAnalytics();
//         }
//         return analytics;
//     }
// }

// Thread-safe Singleton Design Pattern Example with lazy loading and double-checked locking
// This implementation is efficient and ensures that the instance is created only when needed
// class JudgeAnalytics {
//     private static volatile JudgeAnalytics analytics;

//     private JudgeAnalytics() {
//         // Private constructor to prevent instantiation
//     }

//     public static JudgeAnalytics getInstance() {
//         if (analytics == null) {
//             synchronized (JudgeAnalytics.class) {
//                 if (analytics == null) { // Double-checked locking
//                     analytics = new JudgeAnalytics();
//                 }
//             }
//         }
//         return analytics;
//     }
// }

// Thread-safe Singleton Design Pattern Example with eager loading
// This implementation is simple and ensures that the instance is created at class loading time
// but it may not be suitable for all use cases, especially if the instance is resource-intensive.
// class JudgeAnalytics {

//     private JudgeAnalytics() {
//         // Private constructor to prevent instantiation
//     }

//     private static class Holder {
//         private static final JudgeAnalytics analytics = new JudgeAnalytics();
//     }

//     public static JudgeAnalytics getInstance() {
//         return Holder.analytics;
//     }
// }

public class Main {
    public static void main(String[] args) {
        JudgeAnalytics analytics1 = JudgeAnalytics.getInstance();
        JudgeAnalytics analytics2 = JudgeAnalytics.getInstance();
        System.out.println("Analytics Instance 1: " + analytics1);
        System.out.println("Analytics Instance 2: " + analytics2);

    }
}