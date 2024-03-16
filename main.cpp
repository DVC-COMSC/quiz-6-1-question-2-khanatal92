
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "main.hpp"

using namespace std;

int writeFile() {
    ofstream ofs("employee.txt");
    if (!ofs) {
        cerr << "File Open Error" << endl;
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
    cout << "Employee information has been written to employee.txt" << endl;
    return numEmployees;
}

int readFile() {
    ifstream ifs("employee.txt");
    if (!ifs) {
        cerr << "File Open Error" << endl;
        return -1;
    }

    int numEmployees;
    ifs >> numEmployees;
    cout << setw(12) << "ID" << setw(20) << "Name" << setw(20) << "Department" << setw(12) << "Salary" << endl;

    int employeeID;
    string employeeName, departmentName;
    double salary;
    double totalSalary = 0;

    for (int i = 0; i < numEmployees; ++i) {
        ifs >> employeeID >> employeeName >> departmentName >> salary;

        cout << setw(12) << employeeID << setw(20) << employeeName << setw(20) << departmentName << setw(12) << salary << endl;

        totalSalary += salary;
    }

    cout << setw(52) << "Total: " << setw(12) << totalSalary << " Average: " << setw(12) << fixed << setprecision(2) << (totalSalary / numEmployees) << endl;

    ifs.close();
    return 0;
}

int main() {
    writeFile();
    readFile();
    return 0;
}