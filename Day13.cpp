//modify string k times
#include <iostream>
#include <string>
#include <cctype>

std::string modifyString(const std::string& s, int k) {
    std::string modifiedString = s;
    for (int i = 0; i < modifiedString.length(); i++) {
        if (k == 0)
            break;
            
            if (modifiedString[i] >= 'A' && modifiedString[i] <= 'Z')
            continue;
            
            modifiedString[i] = toupper(modifiedString[i]);
        k--; 
    }

    return modifiedString;
}

int main() {
    std::string s;
    int k;

    std::cout << "Enter the string: ";
    std::cin >> s;

    std::cout << "Enter the value of k: ";
    std::cin >> k;

    std::string modifiedString = modifyString(s, k);
    std::cout << "Modified string: " << modifiedString << std::endl;

    return 0;
}
//modify string k times
#include <iostream>
#include <string>
#include <cctype>

std::string modifyString(const std::string& s, int k) {
    std::string modifiedString = s;
    for (int i = 0; i < modifiedString.length(); i++) {
        if (k == 0)
            break;
            
            if (modifiedString[i] >= 'A' && modifiedString[i] <= 'Z')
            continue;
            
            modifiedString[i] = toupper(modifiedString[i]);
        k--; 
    }

    return modifiedString;
}

int main() {
    std::string s;
    int k;

    std::cout << "Enter the string: ";
    std::cin >> s;

    std::cout << "Enter the value of k: ";
    std::cin >> k;

    std::string modifiedString = modifyString(s, k);
    std::cout << "Modified string: " << modifiedString << std::endl;

    return 0;
}
