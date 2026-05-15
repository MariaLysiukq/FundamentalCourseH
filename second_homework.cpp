#include <iostream>
#include <string>
#include <vector>    
#include <list>      
#include <queue>     
#include <algorithm> 

using namespace std;

class Employee {
public:
    string name;
    string department;
    double salary;
    double monthlySalaries[12];

    Employee(string n, string d, double s) : name(n), department(d), salary(s) {
        for(int i = 0; i < 12; i++) monthlySalaries[i] = s;
    }

    void display() const {
        cout << "Name: " << name << "\ndepartament: " << department << "\nsalary: " << salary << endl;
    }
};

class BusinessResourceManager {
private:
    vector<Employee> employees; 
    list<string> tasks;         
    queue<string> taskQueue;    

public:
    void addEmployee(const Employee& e) {
        employees.push_back(e);
    }

    void searchByName(string name) {
        bool found = false;
        for (const auto& e : employees) {
            if (e.name == name) {
                cout << "Find: ";
                e.display();
                found = true;
            }
        }
        if (!found) cout << "Covorker: " << name << " wasnt found." << endl;
    }

    void sortBySalary() {
        sort(employees.begin(), employees.end(), [](const Employee& a, const Employee& b) {
            return a.salary > b.salary;
        });
        cout << "sorted by salary" << endl;
    }

    void removeEmployee(string name) {
        auto it = remove_if(employees.begin(), employees.end(), [&](const Employee& e) {
            return e.name == name;
        });
        if (it != employees.end()) {
            employees.erase(it, employees.end());
            cout << "worker" << name << " deleted" << endl;
        } else {
            cout << "Error. worker not found" << endl;
        }
    }

    void addTask(string task) {
        taskQueue.push(task);
        cout << "added task: " << task << endl;
    }

    void processTask() {
        if (!taskQueue.empty()) {
            cout << "do task: " << taskQueue.front() << endl;
            taskQueue.pop();
        } else {
            cout << "queue is empty" << endl;
        }
    }

    void showAllEmployees() {
        cout << "\nlist of workers" << endl;
        for (const auto& e : employees) e.display();
    }
};


int main() {
    BusinessResourceManager manager;

    manager.addEmployee(Employee("1", "IT", 45000));
    manager.addEmployee(Employee("2", "HR", 32000));
    manager.addEmployee(Employee("3", "Sales", 38000));

    manager.sortBySalary();
    manager.showAllEmployees();

    cout << "\nlooking for '1':" << endl;
    manager.searchByName("1");

    cout << "\nqueue:" << endl;
    manager.addTask("zvit");
    manager.addTask("meeting");
    manager.processTask();

    cout << "\nDeleting '3':" << endl;
    manager.removeEmployee("3");
    manager.showAllEmployees();

    return 0;
}