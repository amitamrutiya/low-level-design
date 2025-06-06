
import java.util.ArrayList;
import java.util.List;

interface DocumentSessionMediator {
    void broadcastChange(String change, User sender);

    void Join(User user);
}

class CollaborativeDocumentSession implements DocumentSessionMediator {
    private List<User> users;

    public CollaborativeDocumentSession() {
        this.users = new ArrayList<>();
    }

    @Override
    public void broadcastChange(String change, User sender) {
        for (User user : users) {
            if (user != sender) {
                user.receiveChange(sender, change);
            }
        }
    }

    @Override
    public void Join(User user) {
        users.add(user);

    }
}

class User {
    private String name;
    private DocumentSessionMediator mediator;

    public User(String name, DocumentSessionMediator mediator) {
        this.name = name;
        this.mediator = mediator;
    }

    public void makeChange(String change) {
        System.out.println(name + " made a change: " + change);
        mediator.broadcastChange(change, this);
    }

    public void receiveChange(User from, String change) {
        System.out.println(name + " received a change from " + from.name + ": " + change);
    }
}

public class Main {
    public static void main(String[] args) {
        DocumentSessionMediator session = new CollaborativeDocumentSession();

        User alice = new User("Alice", session);
        User bob = new User("Bob", session);
        User charlie = new User("Charlie", session);

        session.Join(alice);
        session.Join(bob);
        session.Join(charlie);

        alice.makeChange("Added a new section.");
        bob.makeChange("Fixed a typo.");
        charlie.makeChange("Updated the formatting.");
    }
}
