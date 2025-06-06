abstract class NotificationSender {
    public final void send(String to, String message) {
        checkRateLimit(to);
        validateRecipient(to);
        String formattedMessage = formatMessage(message);
        logBeforeSend(formattedMessage, to);
        String composedMessage = componseMessage(formattedMessage);
        sendNotification(to, composedMessage);
        logAfterSend(composedMessage, to);
        recordAnalytics(to);
    }

    private void checkRateLimit(String to) {
        System.out.println("Checking rate limit for notifications for " + to);
    }

    private void validateRecipient(String to) {
        System.out.println("Validating recipient: " + to);
    }

    private String formatMessage(String message) {
        return message.trim();
    }

    private void logBeforeSend(String message, String to) {
        System.out.println("Logging before send: " + message + " to " + to);
    }

    private void logAfterSend(String message, String to) {
        System.out.println("Logging after send: " + message + " to " + to);
    }

    protected void recordAnalytics(String to) {
        System.out.println("Recording analytics for notification sent to " + to);
    }

    protected abstract String componseMessage(String message);

    protected abstract void sendNotification(String to, String message);

}

class EmailNotificationSender extends NotificationSender {
    @Override
    protected String componseMessage(String message) {
        return "Email: " + message;
    }

    @Override
    protected void sendNotification(String to, String message) {
        System.out.println("Sending email to " + to + " with message: " + message);
        System.out.println("Email sent successfully to " + to);
    }
}

class SMSNotificationSender extends NotificationSender {
    @Override
    protected String componseMessage(String message) {
        return "SMS: " + message;
    }

    @Override
    protected void sendNotification(String to, String message) {
        System.out.println("Sending SMS to " + to + " with message: " + message);
        System.out.println("SMS sent successfully to " + to);
    }

    @Override
    protected void recordAnalytics(String to) {
        System.out.println("Recording analytics for SMS sent to " + to);
    }
}

public class Main {
    public static void main(String[] args) {
        NotificationSender emailSender = new EmailNotificationSender();
        String emailTo = "user@xyz.com";
        String emailMessage = "  Hello, this is a test email!  ";
        emailSender.send(emailTo, emailMessage);
        System.out.println();
        NotificationSender smsSender = new SMSNotificationSender();
        String smsTo = "1234567890";
        String smsMessage = "  Hello, this is a test SMS!  ";
        smsSender.send(smsTo, smsMessage);
    }
}
