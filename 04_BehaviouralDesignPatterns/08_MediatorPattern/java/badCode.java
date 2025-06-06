import java.util.ArrayList;
import java.util.List;

class User {
    private String name;
    private List<User> others;

    public User(String name) {
        this.name = name;
        this.others = new ArrayList<>();
    }

    public void addCollaborator(User user) {
        others.add(user);
    }

    public void makeChange(String change) {
        System.out.println(name + " made a change: " + change);
        for (User user : others) {
            user.receiveChange(this, change);
        }
    }

    public void receiveChange(User from, String change) {
        System.out.println(name + " received a change from " + from.name + ": " + change);
    }
}
// Each user has reference to all other users, which leads to tight coupling.
// adding or removing users requires changes in all user classes.
// hard to orchestrate changes, as each user needs to know about all others.
// This can lead to a lot of boilerplate code and potential errors if not
// managed properly.
