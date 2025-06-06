#include <iostream>
#include <string>

// Abstract base class defining the template method
class NotificationTemplate {
protected:
    // These are the primitive operations that can be overridden by subclasses
    virtual void checkRateLimit(const std::string& to) = 0;
    virtual void validateRecipient(const std::string& to) = 0;
    virtual std::string composeMessage(const std::string& to, const std::string& message) = 0;
    virtual void sendMessage(const std::string& to, const std::string& composedMessage) = 0;

    // Common operations that are the same for all notification types
    void logBeforeSend(const std::string& message, const std::string& to) {
        std::cout << "Logging before send: " << message << " to " << to << std::endl;
    }

    void logAfterSend(const std::string& message, const std::string& to) {
        std::cout << "Logging after send: " << message << " to " << to << std::endl;
    }

    void recordAnalytics(const std::string& to) {
        std::cout << "Recording analytics for message sent to " << to << std::endl;
    }

    std::string formatMessage(const std::string& message) {
        std::string formatted = message;
        // Trim the message
        formatted.erase(0, formatted.find_first_not_of(" "));
        formatted.erase(formatted.find_last_not_of(" ") + 1);
        return formatted;
    }

public:
    // This is the template method
    void send(const std::string& to, const std::string& message) {
        checkRateLimit(to);
        validateRecipient(to);
        
        std::string formatted = formatMessage(message);
        logBeforeSend(formatted, to);

        std::string composedMessage = composeMessage(to, formatted);
        sendMessage(to, composedMessage);
        
        logAfterSend(composedMessage, to);
        recordAnalytics(to);
    }

    virtual ~NotificationTemplate() = default;
};

// Concrete class for Email notifications
class EmailNotification : public NotificationTemplate {
protected:
    void checkRateLimit(const std::string& to) override {
        std::cout << "Checking rate limit for email notifications for " << to << std::endl;
    }

    void validateRecipient(const std::string& to) override {
        std::cout << "Validating email address: " << to << std::endl;
    }

    std::string composeMessage(const std::string& to, const std::string& message) override {
        return "Email to " + to + ": " + message;
    }

    void sendMessage(const std::string& to, const std::string& composedMessage) override {
        std::cout << "Sending email to " << to << " with message: " << composedMessage << std::endl;
        std::cout << "Email sent successfully to " << to << std::endl;
    }
};

// Concrete class for SMS notifications
class SMSNotification : public NotificationTemplate {
protected:
    void checkRateLimit(const std::string& to) override {
        std::cout << "Checking rate limit for SMS notifications for " << to << std::endl;
    }

    void validateRecipient(const std::string& to) override {
        std::cout << "Validating phone number: " << to << std::endl;
    }

    std::string composeMessage(const std::string& to, const std::string& message) override {
        return "SMS to " + to + ": " + message;
    }

    void sendMessage(const std::string& to, const std::string& composedMessage) override {
        std::cout << "Sending SMS to " << to << " with message: " << composedMessage << std::endl;
        std::cout << "SMS sent successfully to " << to << std::endl;
    }
};

// Concrete class for Push notifications
class PushNotification : public NotificationTemplate {
protected:
    void checkRateLimit(const std::string& to) override {
        std::cout << "Checking rate limit for push notifications for " << to << std::endl;
    }

    void validateRecipient(const std::string& to) override {
        std::cout << "Validating device token: " << to << std::endl;
    }

    std::string composeMessage(const std::string& to, const std::string& message) override {
        return "Push notification to " + to + ": " + message;
    }

    void sendMessage(const std::string& to, const std::string& composedMessage) override {
        std::cout << "Sending push notification to " << to << " with message: " << composedMessage << std::endl;
        std::cout << "Push notification sent successfully to " << to << std::endl;
    }
};

int main() {
    EmailNotification emailNotification;
    SMSNotification smsNotification;
    PushNotification pushNotification;

    std::cout << "Testing Email Notification:" << std::endl;
    emailNotification.send("user@xyz.com", "  Hello, this is a test email!  ");
    
    std::cout << "\nTesting SMS Notification:" << std::endl;
    smsNotification.send("+1234567890", "  Hello, this is a test SMS!  ");
    
    std::cout << "\nTesting Push Notification:" << std::endl;
    pushNotification.send("device_token_123", "  Hello, this is a test push notification!  ");

    return 0;
}