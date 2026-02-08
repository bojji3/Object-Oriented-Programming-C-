// =================================================
// Filename : Visaya_LE5.cpp
// Author(s) : Kristina Visaya 
// Email : kvisaya@gbox.adnu.edu.ph 
// Exercise Number : 5
// Assignment Number : 
// Description : The program shows new modification of software engineer, accountant, technical lead, and business lead.
// Last modified: May 18, 2023
// =================================================


#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Employee {
public:
    static int employeeCount;

    Employee(string name, double baseSalary) {
        this->name = name;
        this->baseSalary = baseSalary;
        bonusBudget = 0.0;
        employeeCount++;
        this->employeeID = employeeCount;
    }

    double getBaseSalary() {
        return this->baseSalary;
    }

    void setBonus(double bonus) {
        bonusBudget = bonus;
    }

    double getBonus() {
        return bonusBudget;
    }

    string getName() {
        return this->name;
    }

    int getEmployeeID() {
        return this->employeeID;
    }

    Employee* getManager() {
        return this->manager;
    }

    void setManager(Employee* manager) {
        this->manager = manager;
    }

    bool equals(Employee* other) {
        return this->getEmployeeID() == other->getEmployeeID();
    }

    virtual string toString() {
        return to_string(getEmployeeID()) + " " + getName();
    }

    virtual string employeeStatus() {
        return to_string(getEmployeeID()) + " " + getName() + " has a salary of " + to_string(getBaseSalary());
    }

public:
    int employeeID;
    string name;
    double baseSalary;
    double bonusBudget;
    Employee* manager;
};

int Employee::employeeCount = 0;

class Accountant : public Employee {
public:
    Accountant(string name) : Employee(name, 40000.0) {}
};

class TechnicalEmployee : public Employee {
public:
    TechnicalEmployee(string name) : Employee(name, 75000.0) {
        this->checkIns = 0;
    }

    int getSuccessfulCheckIns() {
        return successfulCheckIns;
    }

    bool checkInCode() {
        checkIns++;
        return true;
    }

    virtual string employeeStatus() {
        return to_string(getEmployeeID()) + " " + getName() + " has a salary of " + to_string(getBaseSalary()) + " and has " + to_string(checkIns) + " successful check-ins";
    }

protected:
    int checkIns;
    int successfulCheckIns;
};

class SoftwareEngineer : public TechnicalEmployee {
public:
    SoftwareEngineer(string name) : TechnicalEmployee(name) {
        this->hasCodeAccess = false;
    }

    void setHasCodeAccess(bool access) {
        hasCodeAccess = access;
    }

    bool getHasCodeAccess() {
        return hasCodeAccess;
    }

    string employeeStatus() {
        return to_string(getEmployeeID()) + " " + getName() + " has a salary of " + to_string(getBaseSalary()) + " and has " + to_string(getSuccessfulCheckIns()) + " successful check-ins and has ";
    }

private:
    bool hasCodeAccess;
};

class TechnicalLead : public TechnicalEmployee {
public:
    TechnicalLead(string name) : TechnicalEmployee(name) {
        this->headCount = 4;
    }

    bool hasHeadCount() {
        return directReports.size() < headCount;
    }

    bool addReport(SoftwareEngineer* e) {
        if (hasHeadCount()) {
            directReports.push_back(e);
            e->setManager(this);
            return true;
        }
        return false;
    }

    bool approveCheckIn(SoftwareEngineer* e) {
        if (e->getManager() == this && e->getHasCodeAccess()) {
            successfulCheckIns++;
            return true;
        }
        return false;
    }

    void setTeamSupported(bool supported) {
        teamSupported = supported;
    }

    string toString() {
        return to_string(getEmployeeID()) + " " + getName() + " has a salary of " + to_string(getBaseSalary()) + " and has " + to_string(getSuccessfulCheckIns()) + " successful check-ins and manages the following employees:\n" + getDirectReports();
    }

    virtual string employeeStatus() {
        return to_string(getEmployeeID()) + " " + getName() + " has a salary of " + to_string(getBaseSalary()) + " and is supporting " + (teamSupported ? "supported" : "unsupported") + " employees";
    }

private:
    int headCount;
    bool teamSupported;
    vector<SoftwareEngineer*> directReports;

    string getDirectReports() {
        string result = "";
        for (int i = 0; i < directReports.size(); i++) {
            result += "\t" + directReports[i]->toString() + "\n";
        }
        return result;
    }
};

class BusinessEmployee : public Employee {
public:
    BusinessEmployee(string name) : Employee(name, 50000.0) {}

    virtual string employeeStatus() {
        return to_string(getEmployeeID()) + " " + getName() + " with a budget of " + to_string(getBonus());
    }
};

class BusinessLead : Employee {
public:
    BusinessLead(string name) : Employee(name, 100000.0) {
        this->headCount = 10;
    }

    bool hasHeadCount() {
        return directReports.size() < headCount;
    }

    bool addReport(Accountant* accountant, vector<TechnicalEmployee*>& employees) {
        if (hasHeadCount()) {
            directReports.push_back(accountant);
            accountant->setManager(this);
           this->setBonus(this->getBonus() + accountant->getBaseSalary() * 1.1);
            for (int i = 0; i < employees.size(); i++) {
                if (((SoftwareEngineer*)employees[i]->getManager())->getManager() == this) {
                    accountant->setBonus(accountant->getBonus() + employees[i]->getBaseSalary() * 1.1);
                }
            }
            return true;
        }
        return false;
    }

    void requestBonus(Employee* e, double bonus) {
        if (bonus < bonusBudget) {
            e->setBonus(bonus);
            bonusBudget -= bonus;
        }
    }

    string getTeamStatus() {
        string result = to_string(getEmployeeID()) + " " + getName() + " has " + to_string(directReports.size()) + " direct report(s):\n";
        for (int i = 0; i < directReports.size(); i++) {
            result += directReports[i]->employeeStatus() + "\n";
        }
        return result;
    }

    virtual string employeeStatus() {
        return to_string(getEmployeeID()) + " " + getName() + " with a budget of " + to_string(bonusBudget) + " and " + to_string(directReports.size()) + " direct report(s)";
    }

    vector<Accountant*> directReports;

private:
    int headCount;
    

};
int main()
{

    
    Accountant* employee1 = new Accountant("Patio");
    TechnicalLead* employee2 = new TechnicalLead("Kajia");
    BusinessLead* employee3 = new BusinessLead("Chalice");
    BusinessEmployee* employee4 = new BusinessEmployee("Kiev");
    TechnicalEmployee* employee5 = new TechnicalEmployee("Bashful");    
    SoftwareEngineer* employee6 = new SoftwareEngineer("Fagguard");

    



    cout << employee1->employeeStatus() << endl;
    cout << employee2->employeeStatus() << endl;
    cout << employee3->employeeStatus() << endl;
    cout << employee4->employeeStatus() << endl;
    cout << employee5->employeeStatus() << endl;
    cout << employee6->employeeStatus() << endl << endl;

    cout << "Technical Lead Kajia's team status:" << endl;
    cout << employee2->employeeStatus() << endl;
    cout << "Business Lead Chalice's team status:" << endl;
    cout << employee3->getTeamStatus() << endl;
    
    Employee e("Pogi", 20000);
    Employee f("Ganda", 20000);

    cout << "Employee ID: " << e.getEmployeeID() << endl;
    cout << "Name: " << e.getName() << endl;
    cout << "Base Salary: " << e.getBaseSalary() << endl;
    cout << "Status: " << e.employeeStatus() << endl << endl;

    cout << "Employee ID: " << f.getEmployeeID() << endl;
    cout << "Name: " << f.getName() << endl;
    cout << "Base Salary: " << f.getBaseSalary() << endl;
    cout << "Status: " << f.employeeStatus() << endl << endl;

    TechnicalEmployee t("Systems Architect");

    cout << "Employee ID: " << t.getEmployeeID() << endl;
    cout << "Name: " << t.getName() << endl;
    cout << "Base Salary: " << t.getBaseSalary() << endl;
    cout << "Status: " << t.employeeStatus() << endl << endl;

    BusinessEmployee b("Marketing Head");

    cout << "Employee ID: " << b.getEmployeeID() << endl;
    cout << "Name: " << b.getName() << endl;
    cout << "Base Salary: " << b.getBaseSalary() << endl;
    cout << "Status: " << b.employeeStatus() << endl << endl;

    SoftwareEngineer s("Software Engineer");
    cout << "Employee ID: " << s.getEmployeeID() << endl;
    cout << "Name: " << s.getName() << endl;
    cout << "Base Salary: " << s.getBaseSalary() << endl;

    s.setHasCodeAccess(true);
    cout << "Software Engineer has access to code? " << s.getHasCodeAccess() << endl;
    cout << "Checking in code... " << s.checkInCode() << endl;
    cout << "Successful check-ins: " << s.getSuccessfulCheckIns() << endl;



    return 0;
}
