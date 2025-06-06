#include <iostream>
#include <string>

class YouTubeChannel {
public:
    void uploadNewVideo(const std::string& videoTitle) {
        std::cout << "New video uploaded: " << videoTitle << std::endl;
        std::cout << "All subscribers will be notified of the new video upload." << std::endl;
        std::cout << "Sending notifications to all subscribers..." << std::endl;
        std::cout << "Email sent to subscribers." << std::endl;
    }
};

int main() {
    YouTubeChannel channel;
    channel.uploadNewVideo("Design Patterns in C++");
    channel.uploadNewVideo("Observer Pattern Explained");
    channel.uploadNewVideo("Iterator Pattern in Depth");
    
    return 0;
}