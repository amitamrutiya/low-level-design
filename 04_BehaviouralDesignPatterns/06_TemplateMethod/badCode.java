class EmailNotification {
    public void send(String to, String message) {
        System.out.println("Checking rate limit for email notifications for " + to);
        System.out.println("Validating email address: " + to);
        String formatted = message.trim();
        System.out.println("Logging before send: " + formatted + " to " + to);

        String composedMessage = "Email to " + to + ": " + formatted;
        System.out.println("Sending email to " + to + " with message: " + composedMessage);
        System.out.println("Email sent successfully to " + to);
        System.out.println("Logging after send: " + composedMessage + " to " + to);

        // analytics
        System.out.println("Recording analytics for email sent to " + to);
    }
}

class SMSNotification {
    public void send(String to, String message) {
        System.out.println("Checking rate limit for SMS notifications for " + to);
        System.out.println("Validating phone number: " + to);
        String formatted = message.trim();
        System.out.println("Logging before send: " + formatted + " to " + to);

        String composedMessage = "SMS to " + to + ": " + formatted;
        System.out.println("Sending SMS to " + to + " with message: " + composedMessage);
        System.out.println("SMS sent successfully to " + to);
        System.out.println("Logging after send: " + composedMessage + " to " + to);

        // analytics
        System.out.println("Recording analytics for SMS sent to " + to);
    }
}

public class badCode {
    public static void main(String[] args) {
        EmailNotification emailNotification = new EmailNotification();
        String to = "user@xyz.com";
        String message = "  Hello, this is a test email!  ";
        emailNotification.send(to, message);
    }
}