//Minimum window substring
#include <iostream>
#include <unordered_map>
#include <climits>

std::string minWindowSubstring(const std::string& s, const std::string& t) {
    std::unordered_map<char, int> targetCount, windowCount;
    
    
    for (char c : t)
        targetCount[c]++;
    
    int required = targetCount.size();  
    int formed = 0;  
    int left = 0, right = 0;  
    int minLength = INT_MAX;  
    int start = 0;
    
    while (right < s.length()) {
        
        char c = s[right++];
        windowCount[c]++;
        if (targetCount.count(c) && windowCount[c] == targetCount[c])
            formed++;
            while (left <= right && formed == required) {
           
            if (right - left < minLength) {
                minLength = right - left;
                start = left;
            }
            char removedChar = s[left++];
            windowCount[removedChar]--;
            if (targetCount.count(removedChar) && windowCount[removedChar] < targetCount[removedChar])
                formed--;
        }
    }
    return (minLength == INT_MAX) ? "" : s.substr(start, minLength);
}

int main() {
    std::string s, t;
    
    std::cout << "Enter string s: ";
    std::cin >> s;
    
    std::cout << "Enter string t: ";
    std::cin >> t;
    
    std::string result = minWindowSubstring(s, t);
    
    std::cout << "Minimum window substring: " << result << std::endl;
    
    return 0;
}