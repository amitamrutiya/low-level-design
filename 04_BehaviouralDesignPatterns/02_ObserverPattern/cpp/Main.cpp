#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Observer interface
class Subscriber {
public:
    virtual void update(const std::string& videoTitle) = 0;
    virtual ~Subscriber() = default;
};

// Concrete Observer
class User : public Subscriber {
private:
    std::string name;

public:
    User(const std::string& name) : name(name) {}

    void update(const std::string& videoTitle) override {
        std::cout << name << " received notification about new video: " << videoTitle << std::endl;
    }
};

// Subject interface
class Subject {
public:
    virtual void attach(Subscriber* observer) = 0;
    virtual void detach(Subscriber* observer) = 0;
    virtual void notify(const std::string& videoTitle) = 0;
    virtual ~Subject() = default;
};

// Concrete Subject
class YouTubeChannel : public Subject {
private:
    std::vector<Subscriber*> subscribers;
    std::string channelName;

public:
    YouTubeChannel(const std::string& name) : channelName(name) {}

    void attach(Subscriber* subscriber) override {
        subscribers.push_back(subscriber);
    }

    void detach(Subscriber* subscriber) override {
        subscribers.erase(
            std::remove(subscribers.begin(), subscribers.end(), subscriber),
            subscribers.end()
        );
    }

    void notify(const std::string& videoTitle) override {
        std::cout << "Channel " << channelName << " uploaded new video: " << videoTitle << std::endl;
        for (Subscriber* subscriber : subscribers) {
            subscriber->update(videoTitle);
        }
    }

    void uploadVideo(const std::string& videoTitle) {
        notify(videoTitle);
    }
};

int main() {
    YouTubeChannel channel("CodeMaster");
    
    User* user1 = new User("Alice");
    User* user2 = new User("Bob");
    User* user3 = new User("Charlie");

    channel.attach(user1);
    channel.attach(user2);
    channel.attach(user3);

    channel.uploadVideo("Design Patterns in C++");
    std::cout << "\n";
    
    // Bob unsubscribes
    channel.detach(user2);
    
    channel.uploadVideo("Observer Pattern Explained");

    delete user1;
    delete user2;
    delete user3;

    return 0;
}