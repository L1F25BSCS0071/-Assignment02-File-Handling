/*
 * Name : Mohid amer
 * Reg No : L1F26BSCS0071
 * Assignment : 02 - File Handling
 * Question : Q1 - Stock Report (Debugging)
 */
 // FIX 1: <fstream> was missing, so ifstream and ofstream were unknown
#include <fstream>
#include <iostream>
using namespace std;
int main() {
    ifstream inFile("stock.txt");
    // FIX2: the check was reversed; it must test !inFile 
    if (!inFile) {
        cout << "stock.txt not found!" << endl;
        return 1;
    }
    // FIX 3: the header line was never skipped, so "Code" was read as an item and the reading broke
    inFile.ignore(100, '\n');
    // FIX 4: ios::app is needed, otherwise the old lines of reorder.txt are erased
    ofstream reorder("reorder.txt", ios::app);
    char code[10];
    int qty, count = 0, low = 0;
    double price;
    // FIX 5: total must be double, otherwise the decimals are cut off
    double total = 0;
    while (count < 50 && inFile >> code >> qty >> price) {
        count++;
        total = total + qty * price;
        if (qty < 10) {
            // FIX 6: endl was missing, so all low-stock items were joined on one line
            reorder << code << " " << qty << endl;
            low++;
        }
    }
    inFile.close();
    reorder.close();
    cout << "Items: " << count << endl;
    cout << "Total stock value: " << total << endl;
    cout << "Low stock items: " << low << endl;
    return 0;
}