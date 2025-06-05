interface EmailTemplate {
    void setContent(String content);

    void send(String recipient);
}

class WelcomeEmail implements EmailTemplate {
    private String content;
    private String subject;

    public WelcomeEmail() {
        this.subject = "Welcome to Our Service!";
        this.content = "Hello, thank you for joining us!";
    }

    @Override
    public void setContent(String content) {
        this.content = content;
    }

    @Override
    public void send(String recipient) {
        System.out.println("Sending Welcome Email to " + recipient);
        System.out.println("Subject: " + subject);
        System.out.println("Content: " + content);
    }
}

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
// See goodCode.java for proper implementation using Prototype pattern
public class badCode {
    public static void main(String[] args) {
        WelcomeEmail welcomeEmail = new WelcomeEmail();
        welcomeEmail.setContent("We are excited to have you on board!");

        WelcomeEmail anotherWelcomeEmail = new WelcomeEmail();
        anotherWelcomeEmail.setContent("We are thrilled to see you here!");

    }
}