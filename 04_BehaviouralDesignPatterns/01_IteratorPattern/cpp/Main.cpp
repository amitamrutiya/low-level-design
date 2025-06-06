#include <iostream>
#include <vector>
#include <string>
#include <memory>

class Video {
private:
    std::string title;

public:
    Video(const std::string& title) : title(title) {}

    std::string getTitle() const {
        return title;
    }
};

// Iterator interface
class Iterator {
public:
    virtual bool hasNext() = 0;
    virtual Video* next() = 0;
    virtual ~Iterator() = default;
};

// Collection interface
class Collection {
public:
    virtual Iterator* createIterator() = 0;
    virtual ~Collection() = default;
};

// Concrete Iterator
class PlaylistIterator : public Iterator {
private:
    std::vector<Video>& videos;
    size_t position;

public:
    PlaylistIterator(std::vector<Video>& videos) : videos(videos), position(0) {}

    bool hasNext() override {
        return position < videos.size();
    }

    Video* next() override {
        if (hasNext()) {
            return &videos[position++];
        }
        return nullptr;
    }
};

// Concrete Collection
class YouTubePlaylist : public Collection {
private:
    std::vector<Video> videos;

public:
    void addVideo(const Video& video) {
        videos.push_back(video);
    }

    Iterator* createIterator() override {
        return new PlaylistIterator(videos);
    }
};

int main() {
    YouTubePlaylist playlist;
    playlist.addVideo(Video("Video 1"));
    playlist.addVideo(Video("Video 2"));
    playlist.addVideo(Video("Video 3"));

    // Using iterator to access videos
    std::unique_ptr<Iterator> iterator(playlist.createIterator());
    while (iterator->hasNext()) {
        Video* video = iterator->next();
        std::cout << video->getTitle() << std::endl;
    }

    return 0;
}