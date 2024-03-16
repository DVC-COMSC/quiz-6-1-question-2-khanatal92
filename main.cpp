#include <iostream>
#include <fstream>
#include <string>
#include "main.hpp"

using namespace std;

// Function to write employee information to file
int writeFile(const string& filename) {
    int numEmployees;
    cout << "Enter the number of employees: ";
    cin >> numEmployees;
    cin.ignore(); // Ignore the newline character in the input buffer

    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Unable to open file." << endl;
        return -1;
    }

for (int i = 0; i < numEmployees; ++i) {
        int id;
        string name, department;
        double salary;

        cout << "Enter employee ID, name, department, and salary (separated by spaces): ";
        cin >> id >> name >> department >> salary;
        cin.ignore(); // Ignore the newline character in the input buffer

        file << id << " " << name << " " << department << " " << salary << endl;
    }

    file.close();
    return numEmployees;
}

// Function to read and print employee information from file
int readFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Unable to open file." << endl;
        return -1;
    }

    int numEmployees = 0;
    int id;
    string name, department;
    double salary;

    cout << "Employee information in file:" << endl;
    while (file >> id >> name >> department >> salary) {
        cout << id << " " << name << " " << department << " " << salary << endl;
        ++numEmployees;
    }

    file.close();
    return numEmployees;
}

int main()
{

    string filename;
    int empN;

    filename = "employee.txt";
    empN = writeFile(filename);
    cout << "File created with " << empN << " employee records\n";

    empN = readFile(filename);
    cout << "The total number of employess read " << empN << endl;

    return 0;
}