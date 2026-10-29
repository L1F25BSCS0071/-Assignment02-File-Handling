/*
 * Name : Mohid Amer
 * Reg No : L1F26BSCS0071
 * Assignment : 02 - File Handling
 * Question : Q3 - Scholarship List
 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int main() {
    char path[100];
    cout << "Enter the file name: ";
    cin.getline(path, 100);
    ifstream inFile(path);
    if (!inFile.is_open()) {
        cout << "Could not open " << path << "!" << endl;
        return 1;
    }
    int n;
    inFile >> n;
    inFile.ignore(100, '\n');
    if (n > 30) {
        cout << "Too many students!" << endl;
        return 1;
    }
    ofstream out("scholarship.txt");
    char name[30], top[30] = "";
    double cgpa, sum = 0, best = -1;
    int count = 0, eligible = 0;
    for (int i = 0; i < n; i++) {
        if (!inFile.getline(name, 30, ',')) break;
        if (!(inFile >> cgpa)) break;
        inFile.ignore(100, '\n');
        cout << "[" << name << "] CGPA: " << cgpa << endl;
        count++;
        sum += cgpa;
        if (cgpa >= 3.50) { out << name << "," << cgpa << endl; eligible++; }
        if (cgpa > best) { best = cgpa; strcpy(top, name); }
    }
    inFile.close();
    out.close();
    if (count < n) cout << "Warning: only " << count << " of " << n << " records found." << endl;
    if (count == 0) {
        cout << "No students found!" << endl;
        return 0;
    }
    cout << "Students: " << count << endl;
    cout << "Average CGPA: " << sum / count << endl;
    cout << "Eligible for scholarship: " << eligible << endl;
    cout << "Top student: " << top << " (" << best << ")" << endl;
    return 0;
}
