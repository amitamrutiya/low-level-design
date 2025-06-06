import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

// memento pattern implementation for a resume editor
class ResumeEditor {
    private String name;
    private String education;
    private String experience;
    private List<String> skills;

    public void setName(String name) {
        this.name = name;
    }

    public void setEducation(String education) {
        this.education = education;
    }

    public void setExperience(String experience) {
        this.experience = experience;
    }

    public void setSkills(List<String> skills) {
        this.skills = new ArrayList<>(skills);
    }

    public void printResume() {
        System.out.println("----- Resume -----");
        System.out.println("Name: " + name);
        System.out.println("Education: " + education);
        System.out.println("Experience: " + experience);
        System.out.println("Skills: " + String.join(", ", skills));
        System.out.println("----- Resume -----");
    }

    public Memento save() {
        return new Memento(name, education, experience, List.copyOf(skills));
    }

    public void restore(Memento memento) {
        this.name = memento.name;
        this.education = memento.education;
        this.experience = memento.experience;
        this.skills = new ArrayList<>(memento.skills);
    }

    // Memento class to hold the state of the ResumeEditor
    public static class Memento {
        private final String name;
        private final String education;
        private final String experience;
        private final List<String> skills;

        private Memento(String name, String education, String experience, List<String> skills) {
            this.name = name;
            this.education = education;
            this.experience = experience;
            this.skills = new ArrayList<>(skills);
        }

        public String getName() {
            return name;
        }

        public String getEducation() {
            return education;
        }

        public String getExperience() {
            return experience;
        }

        public List<String> getSkills() {
            return skills;
        }
    }
}

class ResumeHistory {
    private Stack<ResumeEditor.Memento> history = new Stack<>();

    public void save(ResumeEditor editor) {
        history.push(editor.save());
    }

    public void undo(ResumeEditor editor) {
        if (!history.isEmpty()) {
            editor.restore(history.pop());
        } else {
            System.out.println("No more actions to undo.");
        }
    }
}

public class Main {
    public static void main(String[] args) {
        ResumeEditor editor = new ResumeEditor();
        ResumeHistory history = new ResumeHistory();

        // Initial resume state
        editor.setName("John Doe");
        editor.setEducation("B.Sc. in Computer Science");
        editor.setExperience("5 years in software development");
        editor.setSkills(List.of("Java", "Python", "SQL"));
        editor.printResume();

        // Save the current state
        history.save(editor);

        // Modify the resume
        editor.setExperience("6 years in software development");
        editor.setSkills(List.of("Java", "Python", "SQL", "JavaScript"));
        editor.printResume();

        // Undo the last change
        history.undo(editor);
        editor.printResume();

        // Undo again
        history.undo(editor);
        editor.printResume();
    }
}