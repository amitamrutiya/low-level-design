#include <iostream>
#include <stdexcept>

// Example of violating Interface Segregation Principle
// A "fat" interface that forces classes to implement unnecessary methods

class Worker {
public:
    virtual void work() = 0;
    virtual void eat() = 0;
    virtual void sleep() = 0;
    virtual ~Worker() = default;
};

class Human : public Worker {
public:
    void work() override {
        std::cout << "Human is working" << std::endl;
    }

    void eat() override {
        std::cout << "Human is eating" << std::endl;
    }

    void sleep() override {
        std::cout << "Human is sleeping" << std::endl;
    }
};

class Robot : public Worker {
public:
    void work() override {
        std::cout << "Robot is working" << std::endl;
    }

    // Robot doesn't need these methods but is forced to implement them
    void eat() override {
        // Empty or throw error as robots don't eat
        throw std::runtime_error("Robots don't eat");
    }

    void sleep() override {
        // Empty or throw error as robots don't sleep
        throw std::runtime_error("Robots don't sleep");
    }
};

int main() {
    Human human;
    Robot robot;

    human.work();
    human.eat();
    human.sleep();

    robot.work();
    // The following lines would throw exceptions
    // robot.eat();
    // robot.sleep();

    return 0;
}
