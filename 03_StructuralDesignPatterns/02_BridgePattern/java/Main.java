interface VideoQuality {
    void load(String title);
}

class SDQuality implements VideoQuality {
    @Override
    public void load(String title) {
        System.out.println("Loading " + title + " in SD quality");
    }
}

class HDQuality implements VideoQuality {
    @Override
    public void load(String title) {
        System.out.println("Loading " + title + " in HD quality");
    }
}

class FullHDQuality implements VideoQuality {
    @Override
    public void load(String title) {
        System.out.println("Loading " + title + " in Full HD quality");
    }
}

abstract class VideoPlayer {
    protected VideoQuality videoQuality;

    public VideoPlayer(VideoQuality videoQuality) {
        this.videoQuality = videoQuality;
    }

    public abstract void play(String title);
}

class BasicVideoPlayer extends VideoPlayer {

    public BasicVideoPlayer(VideoQuality videoQuality) {
        super(videoQuality);
    }

    @Override
    public void play(String title) {
        System.out.print("Basic Video Player: ");
        videoQuality.load(title);
    }
}

class AdvancedVideoPlayer extends VideoPlayer {

    public AdvancedVideoPlayer(VideoQuality videoQuality) {
        super(videoQuality);
    }

    @Override
    public void play(String title) {
        System.out.print("Advanced Video Player: ");
        videoQuality.load(title);
    }
}

public class Main {
    public static void main(String[] args) {
        VideoQuality sdQuality = new SDQuality();
        VideoQuality hdQuality = new HDQuality();
        VideoQuality fullHdQuality = new FullHDQuality();

        VideoPlayer basicPlayerSD = new BasicVideoPlayer(sdQuality);
        VideoPlayer advancedPlayerHD = new AdvancedVideoPlayer(hdQuality);
        VideoPlayer advancedPlayerFullHD = new AdvancedVideoPlayer(fullHdQuality);

        basicPlayerSD.play("Nature Documentary");
        advancedPlayerHD.play("Action Movie");
        advancedPlayerFullHD.play("Sci-Fi Series");
    }
}