public class Employee {
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

    // Employee data management
    public void saveEmployee() {
        // Database operations to save employee
        System.out.println("Saving employee to database...");
    }

    // Salary calculation
    public double calculateSalary() {
        double tax = salary * 0.2;
        double insurance = salary * 0.1;
        return salary - tax - insurance;
    }

    // Report generation
    public void generateEmployeeReport() {
        System.out.println("Generating PDF report for employee...");
        System.out.println("Employee ID: " + employeeId);
        System.out.println("Name: " + name);
        System.out.println("Position: " + position);
        System.out.println("Salary: " + salary);
    }
}