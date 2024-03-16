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