import java.util.ArrayList;
import java.util.List;

interface Subscriber {
    void update(String videoTitle);
}

class EmailSubscriber implements Subscriber {
    private String email;

    public EmailSubscriber(String email) {
        this.email = email;
    }

    @Override
    public void update(String videoTitle) {
        System.out.println("Email notification sent for new video: " + videoTitle);
    }
}

class SMSSubscriber implements Subscriber {
    private String phoneNumber;

    public SMSSubscriber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    @Override
    public void update(String videoTitle) {
        System.out.println("SMS notification sent to " + phoneNumber + " for new video: " + videoTitle);
    }
}

interface Channel {
    void subscribe(Subscriber subscriber);

    void unsubscribe(Subscriber subscriber);

    void notifySubscribers(String videoTitle);
}

class YouTubeChannel implements Channel {
    private List<Subscriber> subscribers = new ArrayList<>();
    private String channelName;

    public YouTubeChannel(String channelName) {
        this.channelName = channelName;
    }

    @Override
    public void subscribe(Subscriber subscriber) {
        subscribers.add(subscriber);
        System.out.println(subscriber.getClass().getSimpleName() + " subscribed to " + channelName);
    }

    @Override
    public void unsubscribe(Subscriber subscriber) {
        subscribers.remove(subscriber);
        System.out.println(subscriber.getClass().getSimpleName() + " unsubscribed from " + channelName);
    }

    @Override
    public void notifySubscribers(String videoTitle) {
        System.out.println("New video uploaded: " + videoTitle);
        for (Subscriber subscriber : subscribers) {
            subscriber.update(videoTitle);
        }
    }

    public void uploadNewVideo(String videoTitle) {
        System.out.println("Uploading new video: " + videoTitle);
        notifySubscribers(videoTitle);
    }
}

public class Main {
    public static void main(String[] args) {
        YouTubeChannel channel = new YouTubeChannel("Tech Tutorials");
        channel.subscribe(new EmailSubscriber("amit@gmail.com"));
        channel.subscribe(new SMSSubscriber("123-456-7890"));
        channel.uploadNewVideo("Understanding Design Patterns in Java");

    }
}
