#include <iostream>
#include <string>

class EmailNotification {
public:
    void send(const std::string& to, const std::string& message) {
        std::cout << "Checking rate limit for email notifications for " << to << std::endl;
        std::cout << "Validating email address: " << to << std::endl;
        
        std::string formatted = message;
        // Trim the message
        formatted.erase(0, formatted.find_first_not_of(" "));
        formatted.erase(formatted.find_last_not_of(" ") + 1);
        
        std::cout << "Logging before send: " << formatted << " to " << to << std::endl;

        std::string composedMessage = "Email to " + to + ": " + formatted;
        std::cout << "Sending email to " << to << " with message: " << composedMessage << std::endl;
        std::cout << "Email sent successfully to " << to << std::endl;
        std::cout << "Logging after send: " << composedMessage << " to " << to << std::endl;

        // analytics
        std::cout << "Recording analytics for email sent to " << to << std::endl;
    }
};

class SMSNotification {
public:
    void send(const std::string& to, const std::string& message) {
        std::cout << "Checking rate limit for SMS notifications for " << to << std::endl;
        std::cout << "Validating phone number: " << to << std::endl;
        
        std::string formatted = message;
        // Trim the message
        formatted.erase(0, formatted.find_first_not_of(" "));
        formatted.erase(formatted.find_last_not_of(" ") + 1);
        
        std::cout << "Logging before send: " << formatted << " to " << to << std::endl;

        std::string composedMessage = "SMS to " + to + ": " + formatted;
        std::cout << "Sending SMS to " << to << " with message: " << composedMessage << std::endl;
        std::cout << "SMS sent successfully to " << to << std::endl;
        std::cout << "Logging after send: " << composedMessage << " to " << to << std::endl;

        // analytics
        std::cout << "Recording analytics for SMS sent to " << to << std::endl;
    }
};

int main() {
    EmailNotification emailNotification;
    std::string to = "user@xyz.com";
    std::string message = "  Hello, this is a test email!  ";
    emailNotification.send(to, message);

    std::cout << "\n";

    SMSNotification smsNotification;
    to = "+1234567890";
    message = "  Hello, this is a test SMS!  ";
    smsNotification.send(to, message);

    return 0;
}