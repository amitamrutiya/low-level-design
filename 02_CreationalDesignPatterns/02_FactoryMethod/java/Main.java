interface Logistics {
    void send();
}

class Truck implements Logistics {
    @Override
    public void send() {
        System.out.println("Delivering by Truck");
    }
}

class Ship implements Logistics {
    @Override
    public void send() {
        System.out.println("Delivering by Ship");
    }
}

class Airplane implements Logistics {
    @Override
    public void send() {
        System.out.println("Delivering by Airplane");
    }

}

class LogisticsFactory {
    public static Logistics createLogistics(String mode) {
        switch (mode) {
            case "Truck" -> {
                return new Truck();
            }
            case "Ship" -> {
                return new Ship();
            }
            case "Airplane" -> {
                return new Airplane();
            }
            default -> throw new IllegalArgumentException("Unknown delivery mode: " + mode);
        }
    }
}

class LogisticService {
    public void deliver(String mode) {
        Logistics logistics = LogisticsFactory.createLogistics(mode);
        logistics.send();
    }
}

public class Main {
    public static void main(String[] args) {
        LogisticService service = new LogisticService();
        service.deliver("Truck"); // Delivering by Truck
        service.deliver("Ship"); // Delivering by Ship
        service.deliver("Airplane"); // Delivering by Airplane
        // service.deliver("Bike"); // Uncommenting this line will throw an exception
    }
}