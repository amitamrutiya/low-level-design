#include <iostream>
#include <string>
#include <vector>
#include <memory>

class User {
private:
    std::string name;
    std::vector<std::shared_ptr<User>> others;

public:
    User(const std::string& name) : name(name) {}

    void addCollaborator(std::shared_ptr<User> user) {
        others.push_back(user);
    }

    void makeChange(const std::string& change) {
        std::cout << name << " made a change: " << change << std::endl;
        for (const auto& user : others) {
            user->receiveChange(name, change);
        }
    }

    void receiveChange(const std::string& from, const std::string& change) {
        std::cout << name << " received a change from " << from << ": " << change << std::endl;
    }

    std::string getName() const {
        return name;
    }
};

int main() {
    // Create users
    auto user1 = std::make_shared<User>("Alice");
    auto user2 = std::make_shared<User>("Bob");
    auto user3 = std::make_shared<User>("Charlie");

    // Add collaborators for each user
    user1->addCollaborator(user2);
    user1->addCollaborator(user3);
    
    user2->addCollaborator(user1);
    user2->addCollaborator(user3);
    
    user3->addCollaborator(user1);
    user3->addCollaborator(user2);

    // Simulate some changes
    user1->makeChange("Updated the header");
    std::cout << std::endl;
    
    user2->makeChange("Modified the footer");
    std::cout << std::endl;
    
    user3->makeChange("Changed the layout");

    return 0;
}

// Problems with this approach:
// 1. Each user has reference to all other users, leading to tight coupling
// 2. Adding or removing users requires changes in all user objects
// 3. Hard to orchestrate changes as each user needs to know about all others
// 4. Can lead to complex maintenance and potential errors
// 5. No central point of control for communication