//Parentheses combination generator
#include <iostream>
#include <vector>
using namespace std;

void generate(vector<string>& result, string current, int open, int close, int n) {
    if (open == n && close == n) {
        result.push_back(current);
        return;
    }
    
    if (open < n) {
        generate(result, current + "(", open + 1, close, n);
    }
    
    if (close < open) {
        generate(result, current + ")", open, close + 1, n);
    }
}

vector<string> generateParentheses(int n) {
    vector<string> result;
    generate(result, "", 0, 0, n);
    return result;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    
    vector<string> combinations = generateParentheses(n);
    
    cout << "Combinations of well-formed parentheses:" << endl;
    for (const auto& combination : combinations) {
        cout << combination << endl;
    }
    
    return 0;
}
