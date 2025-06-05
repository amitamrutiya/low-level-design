// Example of violating Interface Segregation Principle
// A "fat" interface that forces classes to implement unnecessary methods

interface Worker {
    void work();

    void eat();

    void sleep();
}

class Human implements Worker {
    public void work() {
        System.out.println("Human is working");
    }

    public void eat() {
        System.out.println("Human is eating");
    }

    public void sleep() {
        System.out.println("Human is sleeping");
    }
}

class badCode implements Worker {
    public void work() {
        System.out.println("Robot is working");
    }

    // Robot doesn't need these methods but is forced to implement them
    public void eat() {
        // Empty or throw error as robots don't eat
        throw new UnsupportedOperationException();
    }

    public void sleep() {
        // Empty or throw error as robots don't sleep
        throw new UnsupportedOperationException();
    }
}