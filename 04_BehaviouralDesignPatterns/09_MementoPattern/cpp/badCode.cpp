#include <iostream>
#include <string>
#include <vector>

class ResumeEditor {
public:
    std::string name;
    std::string education;
    std::string experience;
    std::vector<std::string> skills;
};

class ResumeSnapshot {
public:
    std::string name;
    std::string education;
    std::string experience;
    std::vector<std::string> skills;

    explicit ResumeSnapshot(const ResumeEditor& editor) {
        this->name = editor.name;
        this->education = editor.education;
        this->experience = editor.experience;
        this->skills = editor.skills;
    }

    void restore(ResumeEditor& editor) {
        editor.name = this->name;
        editor.education = this->education;
        editor.experience = this->experience;
        editor.skills = this->skills;
    }
};

int main() {
    ResumeEditor editor;
    editor.name = "John Doe";
    editor.education = "Bachelor of Science in Computer Science";
    editor.experience = "5 years of software development experience";
    editor.skills = {"Java", "Python"};

    // Create a snapshot of the current state
    ResumeSnapshot snapshot(editor);

    // Modify the resume
    editor.name = "John Smith";
    editor.education = "Master of Science in Computer Science";
    editor.experience = "6 years of software development experience";
    editor.skills.push_back("JavaScript");

    // Restore the original state from the snapshot
    snapshot.restore(editor);

    // Print the restored resume
    std::cout << "Name: " << editor.name << std::endl;
    std::cout << "Education: " << editor.education << std::endl;
    std::cout << "Experience: " << editor.experience << std::endl;
    std::cout << "Skills: ";
    for (size_t i = 0; i < editor.skills.size(); ++i) {
        std::cout << editor.skills[i];
        if (i < editor.skills.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    return 0;
}

// Problems with this approach:
// 1. Poor encapsulation - all fields are public
// 2. No history management - only one snapshot at a time
// 3. No validation or error handling
// 4. No separation of concerns between editor and snapshot management
// 5. Direct access to internal state
// 6. No way to track or manage multiple versions
// 7. No protection against tampering with snapshots