class RealVideoDownloader {
    public String downloadVideo(String videoUrl) {
        // Simulate downloading a video
        System.out.println("Downloading video from: " + videoUrl);
        return "Video content from " + videoUrl;
    }
}

public class badCode {
    public static void main(String[] args) {
        RealVideoDownloader realVideoDownloader1 = new RealVideoDownloader();
        realVideoDownloader1.downloadVideo("proxy-pattern-video-url");

        RealVideoDownloader realVideoDownloader2 = new RealVideoDownloader();
        realVideoDownloader2.downloadVideo("proxy-pattern-video-url");

    }
}