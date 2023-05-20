//reversing a string by modifying the input array in-place 
#include <iostream>
#include <vector>

void reverseString(std::vector<char>& s) {
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
    
        std::swap(s[left], s[right]);
        left++;
        right--;
    }
}

int main() {
    std::cout << "Enter a string: ";
    std::string input;
    std::getline(std::cin, input);

    std::vector<char> s(input.begin(), input.end());
    reverseString(s);

    for (char ch : s) {
        std::cout << ch;
    }
    std::cout << std::endl;

    return 0;
}
