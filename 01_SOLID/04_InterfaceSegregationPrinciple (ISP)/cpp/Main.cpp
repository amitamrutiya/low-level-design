#include <iostream>

// Segregated interfaces that are specific to each type of functionality
class Workable {
public:
    virtual void work() = 0;
    virtual ~Workable() = default;
};

class Eatable {
public:
    virtual void eat() = 0;
    virtual ~Eatable() = default;
};

class Sleepable {
public:
    virtual void sleep() = 0;
    virtual ~Sleepable() = default;
};

// Human implements all interfaces
class Human : public Workable, public Eatable, public Sleepable {
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

// Robot only implements what it needs
class Robot : public Workable {
public:
    void work() override {
        std::cout << "Robot is working" << std::endl;
    }
};

int main() {
    Human human;
    Robot robot;

    // Human can do everything
    human.work();
    human.eat();
    human.sleep();

    // Robot only works
    robot.work();

    return 0;
}
