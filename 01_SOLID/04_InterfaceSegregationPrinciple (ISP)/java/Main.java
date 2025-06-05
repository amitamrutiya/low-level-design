// Example of following Interface Segregation Principle
// Segregated interfaces that are specific to each type of functionality

interface Workable {
    void work();
}

interface Eatable {
    void eat();
}

interface Sleepable {
    void sleep();
}

class Human implements Workable, Eatable, Sleepable {
    @Override
    public void work() {
        System.out.println("Human is working");
    }

    @Override
    public void eat() {
        System.out.println("Human is eating");
    }

    @Override
    public void sleep() {
        System.out.println("Human is sleeping");
    }
}

class Robot implements Workable {
    @Override
    public void work() {
        System.out.println("Robot is working");
    }
    // Robot only implements what it needs
}