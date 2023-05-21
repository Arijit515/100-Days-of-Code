//Counting palindromic subsequences in a given string
#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 1005;
const int MOD = 1000000007;

int countPalindromicSubsequences(string str) {
    int N = str.length();
    int dp[MAXN][MAXN];

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < N; i++) {
        dp[i][i] = 1;
    }

    for (int len = 2; len <= N; len++) {
        for (int i = 0; i <= N - len; i++) {
            int j = i + len - 1;

            if (str[i] == str[j]) {
                dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] + 1) % MOD;
            } else {
                dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1]) % MOD;
            }

            if (dp[i][j] < 0) {
                dp[i][j] += MOD;
            }
        }
    }

    return dp[0][N - 1];
}

int main() {
    string str;
    cout << "Enter the string: ";
    cin >> str;

    int count = countPalindromicSubsequences(str);
    cout << "Number of palindromic subsequences: " << count << endl;

    return 0;
}
