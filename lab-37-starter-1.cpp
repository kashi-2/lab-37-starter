// Lab 37 -Hash Tables 1 | Akashdeep Singh 
// Demonstrates ASCII sums

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
using namespace std;

// Function prototype
int gen_hash_index(string code);
void print_first_100(map<int, list<string>>& hash_table);

int main() {

    ifstream fin("lab-37-data-3.txt");
    string code;
    long long grand_total = 0;

    // Hash table: key = int, value = list of strings
    map<int, list<string>> hash_table;

    if (!fin) {
        cout << "Error opening file." << endl;
        return 1;
    }

    // Read each code
    while (fin >> code) {

        int hash_index = gen_hash_index(code);

        grand_total += hash_index;

        // Insert into hash table
        hash_table[hash_index].push_back(code);
    }

    fin.close();

    // Output grand total
    cout << "Grand total: " << grand_total << endl << endl;

    // Display first 100 map entries
    cout << "First 100 hash table entries:" << endl;

 int choice;

    do {

        cout << endl;
        cout << "========== HASH TABLE MENU ==========" << endl;
        cout << "1. Print first 100 entries" << endl;
        cout << "2. Search for a key" << endl;
        cout << "3. Add a key" << endl;
        cout << "4. Remove a key" << endl;
        cout << "5. Modify a key" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        while (choice < 1 || choice > 6) {
            cout << "Invalid choice. Enter 1-6: ";
            cin >> choice;
        }

        switch (choice) {

            case 1:
                print_first_100(hash_table);
                break;

            case 6:
                cout << "Exiting program." << endl;
                break;
        }

    } while (choice != 6);

    return 0;
}



// Function definition
int gen_hash_index(string code) {
    int sum = 0;

    for (char ch : code) {
        sum += (int) ch;
    }

    return sum;
} 

void print_first_100(map<int, list<string>>& hash_table) {

    cout << endl;
    cout << "First 100 hash table entries:" << endl;

    int counter = 0;

    for (auto pair : hash_table) {

        cout << "Hash Index: "
             << pair.first
             << " -> ";

        for (string s : pair.second) {
            cout << s << " ";
        }

        cout << endl;

        counter++;

        if (counter >= 100) {
            break;
        }
    }
}
