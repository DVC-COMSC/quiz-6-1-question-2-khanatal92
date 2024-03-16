#include <iostream>
#include <fstream>
#include <string>
#include "main.hpp"

using namespace std;

int writeFile() {
    ofstream ofs("employee.txt");
    if (!ofs.is_open()) {
        cerr << "Error opening file." << endl;
        return -1;
    }

    int numEmployees;
    cout << "Enter the number of employees: ";
    cin >> numEmployees;
    ofs << numEmployees << endl;

    for (int i = 0; i < numEmployees; ++i) {
        int employeeID;
        string employeeName, departmentName;
        double salary;

        cout << "Enter the Employee ID, Name, Department, and Salary for employee " << (i + 1) << ": ";
        cin >> employeeID >> employeeName >> departmentName >> salary;
        ofs << employeeID << " " << employeeName << " " << departmentName << " " << salary << endl;
    }

    ofs.close();
    cout << "Employee information has been written to employee.txt." << endl;
    return numEmployees;
}

int readFile() {
    ifstream ifs("employee.txt");
    if (!ifs.is_open()) {
        cerr << "Error opening file." << endl;
        return -1;
    }

    int numEmployees;
    ifs >> numEmployees;
    cout << "Number of employees: " << numEmployees << endl;

    for (int i = 0; i < numEmployees; ++i) {
        int employeeID;
        string employeeName, departmentName;
        double salary;

        ifs >> employeeID >> employeeName >> departmentName >> salary;
        cout << "Employee " << (i + 1) << ": " << employeeID << " " << employeeName << " " << departmentName << " " << salary << endl;
    }

    ifs.close();
    return numEmployees;
}