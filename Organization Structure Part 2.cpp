// =================================================
// Filename : Sandejo_Visaya_LE4.cpp
// Author(s) : Kristina Visaya & Edmund James Sandejo
// Email : kvisaya@gbox.adnu.edu.ph & esandejo@gbox.adnu.edu.ph
// Exercise Number : 4
// Assignment Number : 
// Description : The program shows the employee information such as their employee id, names, salary, department, and, status.
// Last modified: May 4, 2023
// =================================================

#include <iostream>
#include <string>

using namespace std;

class Employee {
public:

    Employee(string name, double base_salary) {
        this->name = name;
        this->base_salary = base_salary;
        this->employee_id = next_employee_id;
        next_employee_id++;
    }

    // get employee name
    string get_name() const {
        return name;
    }

    // get base salary
    double get_base_salary() const {
        return base_salary;
    }

    // get employee ID
    int get_employee_id() const {
        return employee_id;
    }

    // equality operator
    bool operator==(const Employee& other) const {
        return employee_id == other.employee_id;
    }

    // function of employee's status
    virtual string employee_status() const = 0;

protected:
    string name;
    double base_salary;
    int employee_id;

    static int next_employee_id;
};

int Employee::next_employee_id = 1;

class Manager : public Employee {
public:
    Manager(string name, double base_salary, string department)
        : Employee(name, base_salary) {
        this->department = department;
    }
     //manager status
    string employee_status() const {
        return name + " is a manager in the " + department + " department";
    }

private:
    string department;
};

class Engineer : public Employee {
public:
    Engineer(string name, double base_salary, string specialty)
        : Employee(name, base_salary) {
        this->specialty = specialty;
    }

    // engineer status
    string employee_status() const {
        return name + " is an engineer who is specializing in " + specialty;
    }

private:
    string specialty;
};

class TechnicalEmployee : public Employee {
public:
    TechnicalEmployee(string name)
        : Employee(name, 75000.0) {
        successful_check_ins = 0;
    }

    string employee_status() const {
        return to_string(employee_id) + " " + name + " has " + to_string(successful_check_ins) + " successful check ins";
    }

    int get_successful_check_ins() const {
        return successful_check_ins;
    }

private:
    int successful_check_ins;
};

class BusinessEmployee : public Employee {
public:
    BusinessEmployee(string name)
        : Employee(name, 50000.0) {
        bonus_budget = 200000.0;
        this->bonus_budget -= this->get_base_salary();
    }

    double getBonusBudget() const {
        return this->bonus_budget;
    }

    string employee_status() const {
        return to_string(employee_id) + " " + get_name() + " with a budget of " + to_string(this->getBonusBudget());
    }

private:
    static double bonus_budget;
};

double BusinessEmployee::bonus_budget = 0.0; 

int main() {
    Manager ma("Jillian Cappuccino", 999000.0, "Marketing");
    Engineer en("Laureene Dy", 900000.0, "Hardware");
    TechnicalEmployee te("Cybersecurity Analyst");
    BusinessEmployee be("Financial Manager");

    cout << "Employee ID: " << "(" << ma.get_employee_id() << ") "<< endl;
    cout << "Name: " << ma.get_name() << endl;
    cout << "Salary: " << "earns PHP" << ma.get_base_salary() << " per year. " << endl;
    cout << "Status: " << ma.employee_status() << endl << endl;

    cout << "Employee ID: " << " (" << en.get_employee_id() << ") " << endl;
    cout << "Name: " << en.get_name() << endl;
    cout << "Salary: " << "earns PHP" << en.get_base_salary() << " per year. " << endl;
    cout << "Status: " << en.employee_status() << endl << endl;
    
    cout << "Technical Employee Information" << endl;
    cout << "Employee ID: " << " ("<< te.get_employee_id() << ") " << endl;
    cout << "Name: " << te.get_name() << endl;
    cout << "Salary: " << "Earns PHP" << te.get_base_salary() << endl;
    cout << "Status: " << te.get_successful_check_ins() << " successful check ins " << endl << endl;
    
    cout << "Business Employee Information" << endl;
    cout << "Employee ID: " << " (" << be.get_employee_id() << ") " << endl;
    cout << "Name: " << be.get_name() << endl;
    cout << "Salary : " << " earns PHP" << be.get_base_salary() << endl;
    cout << "Status :" << " with a budget of PHP" << be.getBonusBudget() << endl;


    return 0;

}