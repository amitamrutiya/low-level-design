#include <iostream>
#include <string>
using namespace std;

class EmailTemplate {
public:
    virtual void setContent(string content) = 0;
    virtual void send(string recipient) = 0;
    virtual ~EmailTemplate() = default;
};

class WelcomeEmail : public EmailTemplate {
private:
    string content;
    string subject;

public:
    WelcomeEmail() {
        this->subject = "Welcome to Our Service!";
        this->content = "Hello, thank you for joining us!";
    }

    void setContent(string content) override {
        this->content = content;
    }

    void send(string recipient) override {
        cout << "Sending Welcome Email to " << recipient << endl;
        cout << "Subject: " << subject << endl;
        cout << "Content: " << content << endl;
    }
};

// This is a bad implementation from a performance and maintainability
// perspective:
// 1. Performance Issues:
// - Creates new WelcomeEmail instances from scratch each time
// - Initializes default values repeatedly
// - Inefficient when creating many similar email templates
// 2. Maintainability Issues:
// - Any changes to template initialization require updating constructor
// - No way to create variations of templates without modifying class
//
// Solution using Prototype Pattern would:
// - Clone existing template instead of creating new instances
// - Allow template variations through object copying
// - Improve performance by avoiding repeated initialization
// - Make template customization more flexible
//
// See Main.cpp for proper implementation using Prototype pattern
int main() {
    WelcomeEmail welcomeEmail;
    welcomeEmail.setContent("We are excited to have you on board!");

    WelcomeEmail anotherWelcomeEmail;
    anotherWelcomeEmail.setContent("We are thrilled to see you here!");

    return 0;
}
