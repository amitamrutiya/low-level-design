import java.util.ArrayList;
import java.util.List;

class Video {
    String title;

    public Video(String title) {
        this.title = title;
    }

    public String getTitle() {
        return title;
    }
}

class YoutTubePlaylist {
    private List<Video> videos = new ArrayList<>();

    public void addVideo(Video video) {
        videos.add(video);
    }

    public List<Video> getVideos() {
        return videos;
    }
}

public class badCode {
    public static void main(String[] args) {
        YoutTubePlaylist playlist = new YoutTubePlaylist();
        playlist.addVideo(new Video("Video 1"));
        playlist.addVideo(new Video("Video 2"));
        playlist.addVideo(new Video("Video 3"));

        // Directly accessing videos without an iterator
        for (Video video : playlist.getVideos()) {
            System.out.println(video.getTitle());
        }
    }
}