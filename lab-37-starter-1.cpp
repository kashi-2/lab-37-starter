// Lab 37 - Milestone 1
// Demonstrates ASCII sums

#include <iostream>
#include <string>
using namespace std;

// Function prototype
int sum_ascii(string s);

int main() {

    // Test string
    string test = "ABC";

    // Call function
    int result = sum_ascii(test);

    // Output result
    cout << "String: " << test << endl;
    cout << "ASCII sum: " << result << endl;

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
