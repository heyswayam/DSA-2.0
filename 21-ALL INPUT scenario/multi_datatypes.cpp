#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<float> f;
    vector<string> s;
    vector<int> v;

    string input_data;
    getline(cin,input_data);
    stringstream ss(input_data);
    string str;
    while (getline(ss, str, ';')) { // splits on the basis of ;
        stringstream sso(str);
        string fo, so, io;

        getline(sso, fo, ',');
        f.push_back(stof(fo));

        getline(sso, so, ',');
        s.push_back(so); // No conversion needed for string

        getline(sso, io, ',');
        v.push_back(stoi(io)); // Use stoi for integer conversion
    }

    // Output the vectors to verify the results
    for (float num : f) {
        cout << num << " ";
    }
    cout << endl;

    for (const string& str : s) {
        cout << str << " ";
    }
    cout << endl;

    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}