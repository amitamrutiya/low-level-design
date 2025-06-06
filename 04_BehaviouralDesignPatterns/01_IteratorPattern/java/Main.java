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

// class YoutTubePlaylist {
//     private List<Video> videos = new ArrayList<>();

//     public void addVideo(Video video) {
//         videos.add(video);
//     }

//     public List<Video> getVideos() {
//         return videos;
//     }
// }

interface PlaylistIterator {
    boolean hasNext();
    Video next();
}

class YoutTubePlaylistIterator implements PlaylistIterator {
    private List<Video> videos;
    private int position;

    public YoutTubePlaylistIterator(List<Video> videos) {
        this.videos = videos;
        this.position = 0;
    }

    @Override
    public boolean hasNext() {
        return position < videos.size();
    }

    @Override
    public Video next() {
        if (!hasNext()) {
            throw new IndexOutOfBoundsException("No more videos in the playlist");
        }
        return videos.get(position++);
    }
}

// Iterable interface
interface Playlist {
    PlaylistIterator createIterator();
    PlaylistIterator createCopyrightIterator();
}

class YoutTubePlaylist implements Playlist {
    private List<Video> videos = new ArrayList<>();

    public void addVideo(Video video) {
        videos.add(video);
    }

    @Override
    public PlaylistIterator createIterator() {
        return new YoutTubePlaylistIterator(videos);
    }

    @Override
    public PlaylistIterator createCopyrightIterator() {
        // This method can be implemented to return a different iterator if needed
        return new YoutTubePlaylistIterator(videos);
    }
}

public class Main {
    public static void main(String[] args) {
        YoutTubePlaylist playlist = new YoutTubePlaylist();
        playlist.addVideo(new Video("Video 1"));
        playlist.addVideo(new Video("Video 2"));
        playlist.addVideo(new Video("Video 3"));
        playlist.addVideo(new Video("Video 4"));
        playlist.addVideo(new Video("Video 5"));

        PlaylistIterator iterator = playlist.createIterator();

        while (iterator.hasNext()) {
            Video video = iterator.next();
            System.out.println(video.getTitle());
        }
    }
}