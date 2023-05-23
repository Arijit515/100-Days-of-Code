//String rotation problem

#include <iostream>
#include <string>

using namespace std;

bool isRotation(const string& s1, const string& s2) {
    if (s1.length() != s2.length())
        return false;

    string concat = s1 + s1;
    return concat.find(s2) != string::npos;
}

int main() {
    string s1, s2;
    cout << "Enter string s1: ";
    cin >> s1;
    cout << "Enter string s2: ";
    cin >> s2;

    if (isRotation(s1, s2))
        cout << "s2 is a rotation of s1." << endl;
    else
        cout << "s2 is not a rotation of s1." << endl;

    return 0;
}
