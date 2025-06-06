class YouTubeChannel {
    public void uploadNewVideo(String videoTitle) {
        System.out.println("New video uploaded: " + videoTitle);
        System.out.println("All subscribers will be notified of the new video upload.");
        System.out.println("Sending notifications to all subscribers...");
        System.out.println("Email sent to subscribers.");
    }
}

public class badCode {
    public static void main(String[] args) {
        YouTubeChannel channel = new YouTubeChannel();
        channel.uploadNewVideo("Design Patterns in Java");
        channel.uploadNewVideo("Observer Pattern Explained");
        channel.uploadNewVideo("Iterator Pattern in Depth");
    }
}