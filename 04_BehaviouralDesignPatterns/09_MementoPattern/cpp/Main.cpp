#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stack>
#include <ctime>

// Memento class - stores the state
class ResumeMemento {
private:
    friend class Resume; // Only Resume can access private members

    struct State {
        std::string name;
        std::string education;
        std::string experience;
        std::vector<std::string> skills;
        std::time_t timestamp;
    };

    State state;

    explicit ResumeMemento(const State& state) : state(state) {}

public:
    std::time_t getTimestamp() const {
        return state.timestamp;
    }
};

// Originator class
class Resume {
private:
    std::string name;
    std::string education;
    std::string experience;
    std::vector<std::string> skills;

public:
    // Setters with validation
    void setName(const std::string& name) {
        if (name.empty()) {
            throw std::invalid_argument("Name cannot be empty");
        }
        this->name = name;
    }

    void setEducation(const std::string& education) {
        if (education.empty()) {
            throw std::invalid_argument("Education cannot be empty");
        }
        this->education = education;
    }

    void setExperience(const std::string& experience) {
        if (experience.empty()) {
            throw std::invalid_argument("Experience cannot be empty");
        }
        this->experience = experience;
    }

    void addSkill(const std::string& skill) {
        if (skill.empty()) {
            throw std::invalid_argument("Skill cannot be empty");
        }
        skills.push_back(skill);
    }

    // Create a memento containing a snapshot of current state
    std::unique_ptr<ResumeMemento> save() const {
        ResumeMemento::State state{
            name,
            education,
            experience,
            skills,
            std::time(nullptr)
        };
        return std::make_unique<ResumeMemento>(state);
    }

    // Restore state from a memento
    void restore(const ResumeMemento& memento) {
        name = memento.state.name;
        education = memento.state.education;
        experience = memento.state.experience;
        skills = memento.state.skills;
    }

    // Display current state
    void display() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Education: " << education << std::endl;
        std::cout << "Experience: " << experience << std::endl;
        std::cout << "Skills: ";
        for (size_t i = 0; i < skills.size(); ++i) {
            std::cout << skills[i];
            if (i < skills.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }
};

// Caretaker class - maintains history of mementos
class ResumeHistory {
private:
    Resume& resume;
    std::stack<std::unique_ptr<ResumeMemento>> history;
    std::stack<std::unique_ptr<ResumeMemento>> redoHistory;
    const size_t maxHistory;

public:
    explicit ResumeHistory(Resume& resume, size_t maxHistory = 10) 
        : resume(resume), maxHistory(maxHistory) {}

    void save() {
        // Clear redo history when new change is made
        while (!redoHistory.empty()) {
            redoHistory.pop();
        }

        history.push(resume.save());
        
        // Maintain history size limit
        if (history.size() > maxHistory) {
            history.pop();
        }
    }

    bool undo() {
        if (history.empty()) {
            std::cout << "No more history to undo" << std::endl;
            return false;
        }

        redoHistory.push(resume.save());
        resume.restore(*history.top());
        history.pop();
        return true;
    }

    bool redo() {
        if (redoHistory.empty()) {
            std::cout << "No more changes to redo" << std::endl;
            return false;
        }

        history.push(resume.save());
        resume.restore(*redoHistory.top());
        redoHistory.pop();
        return true;
    }

    void displayHistory() const {
        std::cout << "\nUndo history timestamps:" << std::endl;
        std::stack<std::unique_ptr<ResumeMemento>> temp = history;
        while (!temp.empty()) {
            std::time_t timestamp = temp.top()->getTimestamp();
            std::cout << std::ctime(&timestamp);
            temp.pop();
        }
    }
};

int main() {
    try {
        Resume resume;
        ResumeHistory history(resume);

        // Initial state
        resume.setName("John Doe");
        resume.setEducation("Bachelor of Science in Computer Science");
        resume.setExperience("5 years of software development experience");
        resume.addSkill("Java");
        resume.addSkill("Python");
        history.save();
        std::cout << "Initial Resume:" << std::endl;
        resume.display();

        // Make some changes
        std::cout << "\nUpdating resume..." << std::endl;
        resume.setName("John Smith");
        resume.setEducation("Master of Science in Computer Science");
        resume.setExperience("6 years of software development experience");
        resume.addSkill("JavaScript");
        history.save();
        resume.display();

        // Undo changes
        std::cout << "\nUndo last changes:" << std::endl;
        history.undo();
        resume.display();

        // Redo changes
        std::cout << "\nRedo last changes:" << std::endl;
        history.redo();
        resume.display();

        // Show history
        history.displayHistory();

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}