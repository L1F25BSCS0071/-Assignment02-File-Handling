/*
 * Name : <Mohid amer>
 * Reg No : <L1f25bscs0071>
 * Assignment : 02 - File Handling
 * Question : Q2 - Parking Report
 */
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int main() {
    ifstream inFile("parking.txt");
    if (!inFile) {
        cout << "parking.txt not found!" << endl;
        return 1;
    }
    int d, m, y;
    char slash;
    inFile >> d >> slash >> m >> slash >> y;
    inFile.ignore(100, '\n');   // rest of line 1
    inFile.ignore(100, '\n');   // header line
    cout << "Parking report for " << d << "/" << m << "/" << y << endl;
    ofstream out("receipts.txt");
    out << "Receipts for " << d << "/" << m << "/" << y << endl;
    char plate[15], type, longest[15] = "";
    int h1, m1, h2, m2;
    char colon;
    int vehicles = 0, cars = 0, bikes = 0, total = 0, longMin = -1;
    while (vehicles < 30 && inFile >> plate >> type >> h1 >> colon >> m1 >> h2 >> colon >> m2) {
        int minutes = (h2 * 60 + m2) - (h1 * 60 + m1);
        int hours = (minutes + 59) / 60;
        if (hours == 0) hours = 1;
        int fee;
        if (type == 'C') { fee = hours * 100; cars++; cout << plate << " Car "; }
        else { fee = hours * 40;  bikes++; cout << plate << " Bike "; }
        cout << minutes / 60 << " h " << minutes % 60 << " min Fee: " << fee << endl;
        out << plate << " " << fee << endl;
        total += fee;
        vehicles++;
        if (minutes > longMin) { longMin = minutes; strcpy(longest, plate); }
    }
    inFile.close();
    out.close();
    if (vehicles == 0) {
        cout << "No vehicles found!" << endl;
        return 0;
    }
    cout << "Vehicles: " << vehicles << endl;
    cout << "Cars: " << cars << " Bikes: " << bikes << endl;
    cout << "Total collected: " << total << endl;
    cout << "Longest stay: " << longest << " (" << longMin / 60 << " h " << longMin % 60 << " min)" << endl;
    return 0;
}