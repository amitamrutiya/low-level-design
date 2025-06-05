#include <iostream>
#include <string>

// Notification base class
class Notification {
public:
    virtual void sendNotification() {
        std::cout << "Notification sent" << std::endl;
    }
    virtual ~Notification() = default;
};

// Subclass of Notification class for Email Notification
class EmailNotification : public Notification {
public:
    void sendNotification() override {
        std::cout << "Email Notification sent" << std::endl;
    }
};

// Subclass of Notification class for Text Notification
class TextNotification : public Notification {
public:
    void sendNotification() override {
        std::cout << "Text Notification sent" << std::endl;
    }
};

int main() {
    /* Replaced the Notification class object
    with one of its subclass' objects */
    Notification* notification = new EmailNotification();
    
    // Working code on the notification object
    notification->sendNotification();
    
    delete notification;
    return 0;
}
