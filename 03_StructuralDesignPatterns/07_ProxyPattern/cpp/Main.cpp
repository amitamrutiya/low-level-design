#include <iostream>
#include <string>
#include <map>
using namespace std;

// Interface
class VideoDownloader {
public:
    virtual string downloadVideo(string videoUrl) = 0;
    virtual ~VideoDownloader() = default;
};

// Real Subject
class RealVideoDownloader : public VideoDownloader {
public:
    string downloadVideo(string videoUrl) override {
        // Simulate downloading a video
        cout << "Downloading video from: " << videoUrl << endl;
        return "Video content from " + videoUrl;
    }
};

// Proxy with caching
class CachedVideoDownloader : public VideoDownloader {
private:
    RealVideoDownloader* realDownloader;
    map<string, string> cache;

public:
    CachedVideoDownloader() : realDownloader(new RealVideoDownloader()) {}

    string downloadVideo(string videoUrl) override {
        if (cache.find(videoUrl) != cache.end()) {
            cout << "Returning cached video for: " << videoUrl << endl;
            return cache[videoUrl];
        } else {
            string videoContent = realDownloader->downloadVideo(videoUrl);
            cache[videoUrl] = videoContent;
            return videoContent;
        }
    }

    ~CachedVideoDownloader() {
        delete realDownloader;
    }
};

int main() {
    VideoDownloader* downloader = new CachedVideoDownloader();

    // First download - will fetch from source
    downloader->downloadVideo("proxy-pattern-video-url");

    // Second download - will fetch from cache
    downloader->downloadVideo("proxy-pattern-video-url");

    delete downloader;
    return 0;
}