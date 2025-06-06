
import java.util.Stack;

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

interface Command {
    void execute();

    void undo();
}

class TurnOnLightCommand implements Command {
    private Light light;

    public TurnOnLightCommand(Light light) {
        this.light = light;
    }

    @Override
    public void execute() {
        light.turnOn();
    }

    @Override
    public void undo() {
        light.turnOff();
    }
}

class TurnOnACCommand implements Command {
    private AC ac;

    public TurnOnACCommand(AC ac) {
        this.ac = ac;
    }

    @Override
    public void execute() {
        ac.turnOn();
    }

    @Override
    public void undo() {
        ac.turnOff();
    }
}

class TurnOnFanCommand implements Command {
    private Fan fan;

    public TurnOnFanCommand(Fan fan) {
        this.fan = fan;
    }

    @Override
    public void execute() {
        fan.turnOn();
    }

    @Override
    public void undo() {
        fan.turnOff();
    }
}

class TurnOffLightCommand implements Command {
    private Light light;

    public TurnOffLightCommand(Light light) {
        this.light = light;
    }

    @Override
    public void execute() {
        light.turnOff();
    }

    @Override
    public void undo() {
        light.turnOn();
    }
}

class TurnOffACCommand implements Command {
    private AC ac;

    public TurnOffACCommand(AC ac) {
        this.ac = ac;
    }

    @Override
    public void execute() {
        ac.turnOff();
    }

    @Override
    public void undo() {
        ac.turnOn();
    }
}

class TurnOffFanCommand implements Command {
    private Fan fan;

    public TurnOffFanCommand(Fan fan) {
        this.fan = fan;
    }

    @Override
    public void execute() {
        fan.turnOff();
    }

    @Override
    public void undo() {
        fan.turnOn();
    }
}

// Invoker
// 6 command
class RemoteControl {
    private Command[] buttons = new Command[6];
    private Stack<Command> commandHistory = new Stack<>();

    public void setCommand(int slot, Command command) {
        buttons[slot] = command;
    }

    public void pressButton(int slot) {
        if (buttons[slot] != null) {
            buttons[slot].execute();
            commandHistory.push(buttons[slot]);
        }
    }

    public void pressUndo() {
        if (!commandHistory.isEmpty()) {
            Command lastCommand = commandHistory.pop();
            lastCommand.undo();
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Light light = new Light();
        AC ac = new AC();
        Fan fan = new Fan();

        RemoteControl remote = new RemoteControl();

        remote.setCommand(0, new TurnOnLightCommand(light));
        remote.setCommand(1, new TurnOffLightCommand(light));
        remote.setCommand(2, new TurnOnACCommand(ac));
        remote.setCommand(3, new TurnOffACCommand(ac));
        remote.setCommand(4, new TurnOnFanCommand(fan));
        remote.setCommand(5, new TurnOffFanCommand(fan));

        remote.pressButton(0); // Light ON
        remote.pressButton(2); // AC ON
        remote.pressButton(4); // Fan ON

        remote.pressUndo(); // Fan OFF
        remote.pressUndo(); // AC OFF
        remote.pressUndo(); // Light OFF
    }
}