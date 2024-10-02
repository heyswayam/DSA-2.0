#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
// For space-separated input: "1 2 3 4 5"
vector<int> input_space_separated() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

// method is same, just use ss>>comma to replace ',' or '['
// For comma-separated input: "1,2,3,4,5"
vector<int> input_comma_separated() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int num;
    char comma;
    while (ss >> num) {
        arr.push_back(num);
        ss >> comma; // Skip the comma
    }
    return arr;
}

// For input with brackets and commas: "[1,2,3,4,5]"
vector<int> input_array_format() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    char c;
    ss >> c; // Skip the opening bracket
    int num;
    while (ss >> num) {
        arr.push_back(num);
        ss >> c; // Skip the comma or closing bracket
        if (c == ']') break; // Stop if closing bracket is encountered (works if not written)
    }
    return arr;
}

int main() {
    // Test space-separated input
    cout << "Enter space-separated numbers: ";
    vector<int> arr1 = input_space_separated();
    cout << "Space-separated: ";
    for (int num : arr1) cout << num << " ";
    cout << endl;

    // Test comma-separated input
    cout << "Enter comma-separated numbers: ";
    vector<int> arr2 = input_comma_separated();
    cout << "Comma-separated: ";
    for (int num : arr2) cout << num << " ";
    cout << endl;

    // Test array format input
    cout << "Enter numbers in array format [1,2,3]: ";
    vector<int> arr3 = input_array_format();
    cout << "Array format: ";
    for (int num : arr3) cout << num << " ";
    cout << endl;

    return 0;
}