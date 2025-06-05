#include <iostream>
#include <string>

// Employee class only handles employee data
class Employee {
private:
    std::string employeeId;
    std::string name;
    std::string position;
    double salary;

public:
    Employee(std::string empId, std::string n, std::string pos, double sal) 
        : employeeId(empId), name(n), position(pos), salary(sal) {}

    // Getters
    std::string getEmployeeId() const { return employeeId; }
    std::string getName() const { return name; }
    std::string getPosition() const { return position; }
    double getSalary() const { return salary; }
};

// Handles employee persistence
class EmployeeRepository {
public:
    void save(const Employee& employee) {
        // Database operations to save employee
        std::cout << "Saving employee to database..." << std::endl;
    }
};

// Handles salary calculations
class SalaryCalculator {
public:
    double calculateNetSalary(const Employee& employee) {
        double salary = employee.getSalary();
        double tax = salary * 0.2;
        double insurance = salary * 0.1;
        return salary - tax - insurance;
    }
};

// Handles report generation
class EmployeeReportGenerator {
public:
    void generateReport(const Employee& employee) {
        std::cout << "Generating PDF report for employee..." << std::endl;
        std::cout << "Employee ID: " << employee.getEmployeeId() << std::endl;
        std::cout << "Name: " << employee.getName() << std::endl;
        std::cout << "Position: " << employee.getPosition() << std::endl;
        std::cout << "Salary: " << employee.getSalary() << std::endl;
    }
};

int main() {
    // Create an employee
    Employee employee("E123", "John Doe", "Software Engineer", 100000);

    // Save employee to database
    EmployeeRepository repository;
    repository.save(employee);

    // Calculate net salary
    SalaryCalculator calculator;
    double netSalary = calculator.calculateNetSalary(employee);
    std::cout << "\nNet Salary: $" << netSalary << std::endl;

    // Generate employee report
    EmployeeReportGenerator reportGenerator;
    std::cout << "\nGenerating Employee Report:" << std::endl;
    reportGenerator.generateReport(employee);

    return 0;
}
