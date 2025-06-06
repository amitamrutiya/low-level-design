#include <iostream>
#include <string>

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

class NaiveRemoteControl {
private:
    Light light;
    AC ac;
    Fan fan;
    std::string lastAction;

public:
    NaiveRemoteControl(Light light, AC ac, Fan fan) 
        : light(light), ac(ac), fan(fan), lastAction("") {}

    void turnOnLight() {
        light.turnOn();
        lastAction = "Light ON";
    }

    void turnOffLight() {
        light.turnOff();
        lastAction = "Light OFF";
    }

    void turnOnAC() {
        ac.turnOn();
        lastAction = "AC ON";
    }

    void turnOffAC() {
        ac.turnOff();
        lastAction = "AC OFF";
    }

    void turnOnFan() {
        fan.turnOn();
        lastAction = "Fan ON";
    }

    void turnOffFan() {
        fan.turnOff();
        lastAction = "Fan OFF";
    }

    void pressUndo() {
        if (lastAction == "Light ON") {
            light.turnOff();
            lastAction = "Light OFF";
        }
        else if (lastAction == "Light OFF") {
            light.turnOn();
            lastAction = "Light ON";
        }
        else if (lastAction == "AC ON") {
            ac.turnOff();
            lastAction = "AC OFF";
        }
        else if (lastAction == "AC OFF") {
            ac.turnOn();
            lastAction = "AC ON";
        }
        else if (lastAction == "Fan ON") {
            fan.turnOff();
            lastAction = "Fan OFF";
        }
        else if (lastAction == "Fan OFF") {
            fan.turnOn();
            lastAction = "Fan ON";
        }
    }
};

int main() {
    Light light;
    AC ac;
    Fan fan;
    NaiveRemoteControl remote(light, ac, fan);

    remote.turnOnLight();
    remote.turnOnAC();
    remote.turnOnFan();
    remote.pressUndo(); // Undo fan on
    remote.turnOffLight();
    remote.pressUndo(); // Undo light off

    return 0;
}