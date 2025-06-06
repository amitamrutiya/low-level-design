
import java.util.HashMap;
import java.util.Map;

interface VideoDownloader {
    String downloadVideo(String videoUrl);
}

class RealVideoDownloader implements VideoDownloader {
    @Override
    public String downloadVideo(String videoUrl) {
        // Simulate downloading a video
        System.out.println("Downloading video from: " + videoUrl);
        return "Video content from " + videoUrl;
    }

}

class CachedVideoDownloader implements VideoDownloader {
    private RealVideoDownloader realVideoDownloader;
    private Map<String, String> cache;

    public CachedVideoDownloader() {
        this.realVideoDownloader = new RealVideoDownloader();
        this.cache = new HashMap<>();
    }

    @Override
    public String downloadVideo(String videoUrl) {
        if (cache.containsKey(videoUrl)) {
            System.out.println("Returning cached video for: " + videoUrl);
            return cache.get(videoUrl);
        } else {
            String videoContent = realVideoDownloader.downloadVideo(videoUrl);
            cache.put(videoUrl, videoContent);
            return videoContent;
        }
    }
}

public class Main {
    public static void main(String[] args) {
        VideoDownloader videoDownloader = new CachedVideoDownloader();

        // First download, should hit the real downloader
        String video1 = videoDownloader.downloadVideo("proxy-pattern-video-url");
        System.out.println(video1);

        // Second download, should return cached content
        String video2 = videoDownloader.downloadVideo("proxy-pattern-video-url");
        System.out.println(video2);

        // Download a different video, should hit the real downloader again
        String video3 = videoDownloader.downloadVideo("another-video-url");
        System.out.println(video3);
    }
}