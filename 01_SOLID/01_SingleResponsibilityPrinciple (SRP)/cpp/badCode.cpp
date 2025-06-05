#include <iostream>
#include <string>

class Employee {
private:
    std::string employeeId;
    std::string name;
    std::string position;
    double salary;

public:
    Employee(std::string empId, std::string n, std::string pos, double sal) 
        : employeeId(empId), name(n), position(pos), salary(sal) {}

    // Employee data management
    void saveEmployee() {
        // Database operations to save employee
        std::cout << "Saving employee to database..." << std::endl;
    }

    // Salary calculation
    double calculateSalary() {
        double tax = salary * 0.2;
        double insurance = salary * 0.1;
        return salary - tax - insurance;
    }

    // Report generation
    void generateEmployeeReport() {
        std::cout << "Generating PDF report for employee..." << std::endl;
        std::cout << "Employee ID: " << employeeId << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Position: " << position << std::endl;
        std::cout << "Salary: " << salary << std::endl;
    }
};

int main() {
    Employee emp("E123", "John Doe", "Software Engineer", 100000);
    emp.saveEmployee();
    emp.generateEmployeeReport();
    std::cout << "Net Salary: $" << emp.calculateSalary() << std::endl;
    return 0;
}
