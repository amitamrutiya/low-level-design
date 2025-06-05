#include <iostream>
#include <string>
#include <memory>
#include <unordered_map>
using namespace std;

// Defining the Prototype Interface
class EmailTemplate {
public:
    virtual unique_ptr<EmailTemplate> clone() = 0;
    virtual void setContent(const string& content) = 0;
    virtual void send(const string& to) = 0;
    virtual ~EmailTemplate() = default;
};

// Concrete Class implementing clone logic
class WelcomeEmail : public EmailTemplate {
private:
    string subject;
    string content;

public:
    WelcomeEmail() {
        this->subject = "Welcome to TUF+";
        this->content = "Hi there! Thanks for joining us.";
    }

    unique_ptr<EmailTemplate> clone() override {
        auto clone = make_unique<WelcomeEmail>();
        clone->content = this->content;
        clone->subject = this->subject;
        return clone;
    }

    void setContent(const string& content) override {
        this->content = content;
    }

    void send(const string& to) override {
        cout << "Sending to " << to << ": [" << subject << "] " << content << endl;
    }
};

// Template Registry to store and provide clones
class EmailTemplateRegistry {
private:
    static unordered_map<string, unique_ptr<EmailTemplate>> templates;

public:
    static void initialize() {
        templates["welcome"] = make_unique<WelcomeEmail>();
        // templates["discount"] = make_unique<DiscountEmail>();
        // templates["feature-update"] = make_unique<FeatureUpdateEmail>();
    }

    static unique_ptr<EmailTemplate> getTemplate(const string& type) {
        auto it = templates.find(type);
        if (it != templates.end()) {
            return it->second->clone();
        }
        return nullptr;
    }
};

// Initialize static member
unordered_map<string, unique_ptr<EmailTemplate>> EmailTemplateRegistry::templates;

int main() {
    // Initialize the registry
    EmailTemplateRegistry::initialize();

    // Get and customize templates
    auto welcomeEmail1 = EmailTemplateRegistry::getTemplate("welcome");
    welcomeEmail1->setContent("Hi Alice, welcome to TUF Premium!");
    welcomeEmail1->send("alice@example.com");

    auto welcomeEmail2 = EmailTemplateRegistry::getTemplate("welcome");
    welcomeEmail2->setContent("Hi Bob, thanks for joining!");
    welcomeEmail2->send("bob@example.com");

    // Reuse the base WelcomeEmail structure, just changing dynamic content
    return 0;
}
