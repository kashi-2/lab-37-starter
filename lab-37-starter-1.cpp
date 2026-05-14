// Lab 37 -Hash Tables 1 | Akashdeep Singh 
// Demonstrates ASCII sums

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function prototype
int sum_ascii(string s);

int main() {

    ifstream fin("lab-37-data-3.txt");
    string code;
    long long grand_total = 0;

    if (!fin) {
        cout << "Error opening file." << endl;
        return 1;
    }

    // Read each 12-character code
    while (fin >> code) {
        int value = sum_ascii(code);
        grand_total += value;
    }

    fin.close();

    // Output grand total
    cout << "Grand total: " << grand_total << endl;

    return 0;
}

// Function definition
int sum_ascii(string s) {
    int sum = 0;

    for (char ch : s) {
        sum += (int) ch;
    }

    return sum;
}
