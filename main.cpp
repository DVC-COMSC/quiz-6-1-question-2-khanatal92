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
        cout << employeeID << " " << employeeName << " " << departmentName << " " << salary << endl;
    }

    ifs.close();
    return numEmployees;
}

int main() {
    int numEmployeesWritten = writeFile();
    if (numEmployeesWritten > 0) {
        cout << "Employee information has been written to employee.txt." << endl;
        int numEmployeesRead = readFile();
        if (numEmployeesRead > 0) {
            cout << "Total number of employees read: " << numEmployeesRead << endl;
        } else {
            cerr << "Error reading employee information from file." << endl;
        }
    } else {
        cerr << "Error writing employee information to file." << endl;
    }

    return 0;
}