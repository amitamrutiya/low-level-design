class Light {
    public void turnOn() {
        System.out.println("Light is ON");
    }

    public void turnOff() {
        System.out.println("Light is OFF");
    }
}

class AC {
    public void turnOn() {
        System.out.println("AC is ON");
    }

    public void turnOff() {
        System.out.println("AC is OFF");
    }
}

class Fan {
    public void turnOn() {
        System.out.println("Fan is ON");
    }

    public void turnOff() {
        System.out.println("Fan is OFF");
    }
}

class NaiveRemoteControl {
    private Light light;
    private AC ac;
    private Fan fan;
    private String lastAction = "";

    public NaiveRemoteControl(Light light, AC ac, Fan fan) {
        this.light = light;
        this.ac = ac;
        this.fan = fan;
    }

    public void turnOnLight() {
        light.turnOn();
        lastAction = "Light ON";
    }

    public void turnOffLight() {
        light.turnOff();
        lastAction = "Light OFF";
    }

    public void turnOnAC() {
        ac.turnOn();
        lastAction = "AC ON";
    }

    public void turnOffAC() {
        ac.turnOff();
        lastAction = "AC OFF";
    }

    public void turnOnFan() {
        fan.turnOn();
        lastAction = "Fan ON";
    }

    public void turnOffFan() {
        fan.turnOff();
        lastAction = "Fan OFF";
    }

    public void pressUndo() {
        switch (lastAction) {
            case "Light ON":
                light.turnOff();
                lastAction = "Light OFF";
                break;
            case "Light OFF":
                light.turnOn();
                lastAction = "Light ON";
                break;
            case "AC ON":
                ac.turnOff();
                lastAction = "AC OFF";
                break;
            case "AC OFF":
                ac.turnOn();
                lastAction = "AC ON";
                break;
            case "Fan ON":
                fan.turnOff();
                lastAction = "Fan OFF";
                break;
            case "Fan OFF":
                fan.turnOn();
                lastAction = "Fan ON";
                break;
            default:
                throw new AssertionError();
        }
    }
}

public class badCode {
    public static void main(String[] args) {
        Light light = new Light();
        AC ac = new AC();
        Fan fan = new Fan();
        NaiveRemoteControl remote = new NaiveRemoteControl(light, ac, fan);

        remote.turnOnLight();
        remote.turnOnAC();
        remote.turnOnFan();

        remote.pressUndo(); // Should turn off the fan
        remote.pressUndo(); // Should turn off the AC
        remote.pressUndo(); // Should turn off the light
    }
}