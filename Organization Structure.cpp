// =================================================
// Filename : Sandejo_Visaya_LE3.cpp
// Author(s) : Kristina Visaya & Edmund James Sandejo
// Email : kvisaya@gbox.adnu.edu.ph & esandejo@gbox.adnu.edu.ph
// Exercise Number : 3
// Assignment Number : 
// Description : The program shows the employee information such as their employee id, names, salary, and their specialty.
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




int main() {
    Manager ma("Jillian Cappuccino", 999000.0, "Marketing");
    Engineer en("Laureene Dy", 900000.0, "Hardware");
  

    cout << "Employee ID: " << "(" << ma.get_employee_id() << ") "<< endl;
    cout << "Name: " << ma.get_name() << endl;
    cout << "Salary: " << "earns PHP" << ma.get_base_salary() << " per year. " << endl;
    cout << "Status: " << ma.employee_status() << endl << endl;

    cout << "Employee ID: " << " (" << en.get_employee_id() << ") " << endl;
    cout << "Name: " << en.get_name() << endl;
    cout << "Salary: " << "earns PHP" << en.get_base_salary() << " per year. " << endl;
    cout << "Status: " << en.employee_status() << endl << endl;
    

    return 0;

}