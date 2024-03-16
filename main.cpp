#include "main.hpp"

using namespace std;

int writeFile() {
    ofstream ofs("employee.txt");
    if (!ofs) {
        cout << "File Open Error\n";
        exit(0);
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
    if (!ifs) {
        cout << "File Open Error\n";
        exit(0);
    }

    int numEmployees;
    ifs >> numEmployees;

    cout << endl << "Employee information in employee.txt:" << endl;
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

int main() {
    int numEmployeesWritten = writeFile();
    int numEmployeesRead = readFile();

    cout << "Total employees written: " << numEmployeesWritten << endl;
    cout << "Total employees read: " << numEmployeesRead << endl;

    return 0;
}