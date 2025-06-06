#include <iostream>
#include <string>
using namespace std;

class RealVideoDownloader {
public:
    string downloadVideo(string videoUrl) {
        // Simulate downloading a video
        cout << "Downloading video from: " << videoUrl << endl;
        return "Video content from " + videoUrl;
    }
};

int main() {
    RealVideoDownloader realVideoDownloader1;
    realVideoDownloader1.downloadVideo("proxy-pattern-video-url");

    RealVideoDownloader realVideoDownloader2;
    realVideoDownloader2.downloadVideo("proxy-pattern-video-url");

    return 0;
}