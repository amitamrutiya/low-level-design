import java.util.ArrayList;
import java.util.List;

class ResumeEditor {
    public String name;
    public String education;
    public String experience;
    public List<String> skills;

}

class ResumeSnapshot {
    public String name;
    public String education;
    public String experience;
    public List<String> skills;

    public ResumeSnapshot(ResumeEditor editor) {
        this.name = editor.name;
        this.education = editor.education;
        this.experience = editor.experience;
        this.skills = new ArrayList<>(editor.skills);
    }

    public void restore(ResumeEditor editor) {
        editor.name = this.name;
        editor.education = this.education;
        editor.experience = this.experience;
        editor.skills = new ArrayList<>(this.skills);
    }

}

public class badCode {
    public static void main(String[] args) {
        ResumeEditor editor = new ResumeEditor();
        editor.name = "John Doe";
        editor.education = "Bachelor of Science in Computer Science";
        editor.experience = "5 years of software development experience";
        editor.skills = new ArrayList<>();
        editor.skills.add("Java");
        editor.skills.add("Python");

        // Create a snapshot of the current state
        ResumeSnapshot snapshot = new ResumeSnapshot(editor);

        // Modify the resume
        editor.name = "John Smith";
        editor.education = "Master of Science in Computer Science";
        editor.experience = "6 years of software development experience";
        editor.skills.add("JavaScript");

        // Restore the original state from the snapshot
        snapshot.restore(editor);

        // Print the restored resume
        System.out.println("Name: " + editor.name);
        System.out.println("Education: " + editor.education);
        System.out.println("Experience: " + editor.experience);
        System.out.println("Skills: " + String.join(", ", editor.skills));
    }
}