//reversing a string by modifying the input array in-place 
#include <iostream>
#include <vector>

void reverseString(std::vector<char>& s) {
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
        // Swap characters at left and right indices
        std::swap(s[left], s[right]);

        // Move the pointers towards the center
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

    // Print the reversed string
    for (char ch : s) {
        std::cout << ch;
    }
    std::cout << std::endl;

    return 0;
}
