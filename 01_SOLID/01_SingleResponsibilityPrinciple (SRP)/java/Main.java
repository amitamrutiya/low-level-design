// Employee class only handles employee data
class Employee {
    private String employeeId;
    private String name;
    private String position;
    private double salary;

    public Employee(String employeeId, String name, String position, double salary) {
        this.employeeId = employeeId;
        this.name = name;
        this.position = position;
        this.salary = salary;
    }

    // Getters
    public String getEmployeeId() {
        return employeeId;
    }

    public String getName() {
        return name;
    }

    public String getPosition() {
        return position;
    }

    public double getSalary() {
        return salary;
    }
}

// Handles employee persistence
class EmployeeRepository {
    public void save(Employee employee) {
        // Database operations to save employee
        System.out.println("Saving employee to database...");
    }
}

// Handles salary calculations
class SalaryCalculator {
    public double calculateNetSalary(Employee employee) {
        double salary = employee.getSalary();
        double tax = salary * 0.2;
        double insurance = salary * 0.1;
        return salary - tax - insurance;
    }
}

// Handles report generation
class EmployeeReportGenerator {
    public void generateReport(Employee employee) {
        System.out.println("Generating PDF report for employee...");
        System.out.println("Employee ID: " + employee.getEmployeeId());
        System.out.println("Name: " + employee.getName());
        System.out.println("Position: " + employee.getPosition());
        System.out.println("Salary: " + employee.getSalary());
    }
}

public class Main {
    public static void main(String[] args) {
        // Create an employee
        Employee employee = new Employee("E123", "John Doe", "Software Engineer", 100000);

        // Save employee to database
        EmployeeRepository repository = new EmployeeRepository();
        repository.save(employee);

        // Calculate net salary
        SalaryCalculator calculator = new SalaryCalculator();
        double netSalary = calculator.calculateNetSalary(employee);
        System.out.println("\nNet Salary: $" + netSalary);

        // Generate employee report
        EmployeeReportGenerator reportGenerator = new EmployeeReportGenerator();
        System.out.println("\nGenerating Employee Report:");
        reportGenerator.generateReport(employee);
    }
}