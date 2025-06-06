#include <iostream>
#include <vector>
#include <string>

class Video {
private:
    std::string title;

public:
    Video(const std::string& title) : title(title) {}

    std::string getTitle() const {
        return title;
    }
};

class YouTubePlaylist {
private:
    std::vector<Video> videos;

public:
    void addVideo(const Video& video) {
        videos.push_back(video);
    }

    std::vector<Video>& getVideos() {
        return videos;
    }
};

int main() {
    YouTubePlaylist playlist;
    playlist.addVideo(Video("Video 1"));
    playlist.addVideo(Video("Video 2"));
    playlist.addVideo(Video("Video 3"));

    // Directly accessing videos without an iterator
    for (const auto& video : playlist.getVideos()) {
        std::cout << video.getTitle() << std::endl;
    }

    return 0;
}