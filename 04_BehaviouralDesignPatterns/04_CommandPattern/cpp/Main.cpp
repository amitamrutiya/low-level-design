#include <iostream>
#include <string>
#include <memory>
#include <stack>

// Receivers
class Light {
public:
    void turnOn() {
        std::cout << "Light is ON" << std::endl;
    }

    void turnOff() {
        std::cout << "Light is OFF" << std::endl;
    }
};

class AC {
public:
    void turnOn() {
        std::cout << "AC is ON" << std::endl;
    }

    void turnOff() {
        std::cout << "AC is OFF" << std::endl;
    }
};

class Fan {
public:
    void turnOn() {
        std::cout << "Fan is ON" << std::endl;
    }

    void turnOff() {
        std::cout << "Fan is OFF" << std::endl;
    }
};

// Command interface
class Command {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual ~Command() = default;
};

// Concrete Commands for Light
class LightOnCommand : public Command {
private:
    Light& light;

public:
    LightOnCommand(Light& light) : light(light) {}

    void execute() override {
        light.turnOn();
    }

    void undo() override {
        light.turnOff();
    }
};

class LightOffCommand : public Command {
private:
    Light& light;

public:
    LightOffCommand(Light& light) : light(light) {}

    void execute() override {
        light.turnOff();
    }

    void undo() override {
        light.turnOn();
    }
};

// Concrete Commands for AC
class ACOnCommand : public Command {
private:
    AC& ac;

public:
    ACOnCommand(AC& ac) : ac(ac) {}

    void execute() override {
        ac.turnOn();
    }

    void undo() override {
        ac.turnOff();
    }
};

class ACOffCommand : public Command {
private:
    AC& ac;

public:
    ACOffCommand(AC& ac) : ac(ac) {}

    void execute() override {
        ac.turnOff();
    }

    void undo() override {
        ac.turnOn();
    }
};

// Concrete Commands for Fan
class FanOnCommand : public Command {
private:
    Fan& fan;

public:
    FanOnCommand(Fan& fan) : fan(fan) {}

    void execute() override {
        fan.turnOn();
    }

    void undo() override {
        fan.turnOff();
    }
};

class FanOffCommand : public Command {
private:
    Fan& fan;

public:
    FanOffCommand(Fan& fan) : fan(fan) {}

    void execute() override {
        fan.turnOff();
    }

    void undo() override {
        fan.turnOn();
    }
};

// Invoker
class RemoteControl {
private:
    std::stack<std::shared_ptr<Command>> history;

public:
    void pressButton(std::shared_ptr<Command> command) {
        command->execute();
        history.push(command);
    }

    void pressUndo() {
        if (!history.empty()) {
            auto command = history.top();
            command->undo();
            history.pop();
        }
    }
};

int main() {
    // Create receivers
    Light light;
    AC ac;
    Fan fan;

    // Create commands
    auto lightOn = std::make_shared<LightOnCommand>(light);
    auto lightOff = std::make_shared<LightOffCommand>(light);
    auto acOn = std::make_shared<ACOnCommand>(ac);
    auto acOff = std::make_shared<ACOffCommand>(ac);
    auto fanOn = std::make_shared<FanOnCommand>(fan);
    auto fanOff = std::make_shared<FanOffCommand>(fan);

    // Create invoker
    RemoteControl remote;

    // Use the remote
    remote.pressButton(lightOn);
    remote.pressButton(acOn);
    remote.pressButton(fanOn);
    remote.pressUndo(); // Undo fan on
    remote.pressButton(lightOff);
    remote.pressUndo(); // Undo light off

    return 0;
}