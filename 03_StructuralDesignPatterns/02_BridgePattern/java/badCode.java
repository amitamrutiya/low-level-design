interface PlayQuality {
    void play(String title);
}

class WebHDPlayer implements PlayQuality {
    @Override
    public void play(String title) {
        System.out.println("Playing " + title + " in Web HD quality");
    }
}

class MobileHDPlayer implements PlayQuality {
    @Override
    public void play(String title) {
        System.out.println("Playing " + title + " in Mobile HD quality");
    }
}

class SmartTVUltraHDPlayer implements PlayQuality {
    @Override
    public void play(String title) {
        System.out.println("Playing " + title + " in Smart TV Ultra HD quality");
    }
}

// This is a bad implementation of the Bridge Pattern
// because it tightly couples the video player with the quality of playback.
// If we want to add a new quality, we have to modify the existing classes.
// This violates the Open/Closed Principle, which states that classes should be open for extension but closed for modification.
// A better approach would be to use the Bridge Pattern to decouple the video player from the quality of playback.
// This allows us to add new qualities without modifying the existing classes.
// This code is just a demonstration of the bad implementation of the Bridge Pattern.
// The Bridge Pattern is a structural design pattern that decouples an abstraction from its implementation,
// allowing the two to vary independently.
// The Bridge Pattern is useful when you want to separate the abstraction from the implementation,
// allowing you to change the implementation without affecting the abstraction.
// The Bridge Pattern is also useful when you want to avoid a permanent binding between an abstraction and its implementation.
// The Bridge Pattern is a structural design pattern that allows you to decouple an abstraction from its implementation.
// The Bridge Pattern is useful when you want to separate the abstraction from the implementation,
// allowing you to change the implementation without affecting the abstraction.
// The Bridge Pattern is also useful when you want to avoid a permanent binding between an abstraction and its implementation.
// The Bridge Pattern is a structural design pattern that decouples an abstraction from its implementation,         

public class badCode {
    public static void main(String[] args) {

    }
}