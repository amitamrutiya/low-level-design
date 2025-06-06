#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>

// Forward declarations
class User;
class ChatMediator;

// Mediator interface
class Mediator {
public:
    virtual void sendMessage(const std::string& message, const std::string& userId) = 0;
    virtual void addUser(std::shared_ptr<User> user) = 0;
    virtual ~Mediator() = default;
};

// User interface (Colleague)
class User {
protected:
    std::string id;
    std::weak_ptr<Mediator> mediator;

public:
    User(const std::string& id) : id(id) {}

    void setMediator(std::shared_ptr<Mediator> m) {
        mediator = m;
    }

    virtual void send(const std::string& message) {
        if (auto m = mediator.lock()) {
            std::cout << id << " sending message: " << message << std::endl;
            m->sendMessage(message, id);
        }
    }

    virtual void receive(const std::string& message, const std::string& from) {
        std::cout << id << " received message from " << from << ": " << message << std::endl;
    }

    std::string getId() const {
        return id;
    }

    virtual ~User() = default;
};

// Concrete Mediator
class ChatMediator : public Mediator, public std::enable_shared_from_this<ChatMediator> {
private:
    std::unordered_map<std::string, std::shared_ptr<User>> users;

public:
    void addUser(std::shared_ptr<User> user) override {
        users[user->getId()] = user;
        user->setMediator(shared_from_this());
    }

    void sendMessage(const std::string& message, const std::string& fromId) override {
        for (const auto& pair : users) {
            if (pair.first != fromId) {
                pair.second->receive(message, fromId);
            }
        }
    }
};

// Concrete User types
class Developer : public User {
public:
    Developer(const std::string& id) : User(id) {}

    void send(const std::string& message) override {
        std::cout << "Developer " << getId() << " sending technical update: " << message << std::endl;
        if (auto m = mediator.lock()) {
            m->sendMessage("Technical: " + message, getId());
        }
    }
};

class Tester : public User {
public:
    Tester(const std::string& id) : User(id) {}

    void send(const std::string& message) override {
        std::cout << "Tester " << getId() << " sending test results: " << message << std::endl;
        if (auto m = mediator.lock()) {
            m->sendMessage("Test Results: " + message, getId());
        }
    }
};

class ProjectManager : public User {
public:
    ProjectManager(const std::string& id) : User(id) {}

    void send(const std::string& message) override {
        std::cout << "Project Manager " << getId() << " sending update: " << message << std::endl;
        if (auto m = mediator.lock()) {
            m->sendMessage("Management Update: " + message, getId());
        }
    }
};

int main() {
    // Create the mediator
    auto chatRoom = std::make_shared<ChatMediator>();

    // Create users
    auto dev1 = std::make_shared<Developer>("Dev1");
    auto dev2 = std::make_shared<Developer>("Dev2");
    auto tester = std::make_shared<Tester>("Tester");
    auto manager = std::make_shared<ProjectManager>("Manager");

    // Register users with the mediator
    chatRoom->addUser(dev1);
    chatRoom->addUser(dev2);
    chatRoom->addUser(tester);
    chatRoom->addUser(manager);

    // Simulate communication
    std::cout << "=== Development Team Communication ===" << std::endl;
    dev1->send("Implemented new feature");
    std::cout << std::endl;

    dev2->send("Fixed critical bug");
    std::cout << std::endl;

    tester->send("All tests passed");
    std::cout << std::endl;

    manager->send("Please prepare for tomorrow's demo");
    std::cout << std::endl;

    return 0;
}