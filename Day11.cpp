// Anagram indices

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> findAnagramIndices(const string& s, const string& p) {
    vector<int> result;
    int sLen = s.length();
    int pLen = p.length();

    if (sLen < pLen)
        return result;

    unordered_map<char, int> pMap, sMap;
    for (char c : p)
        pMap[c]++;

    for (int i = 0; i < pLen; i++)
        sMap[s[i]]++;

    if (sMap == pMap)
        result.push_back(0);

    for (int i = pLen; i < sLen; i++) {
        sMap[s[i - pLen]]--;
        if (sMap[s[i - pLen]] == 0)
            sMap.erase(s[i - pLen]);

        sMap[s[i]]++;
        if (sMap == pMap)
            result.push_back(i - pLen + 1);
    }

    return result;
}

int main() {
    string s, p;
    cout << "Enter the string s: ";
    cin >> s;
    cout << "Enter the string p: ";
    cin >> p;

    vector<int> indices = findAnagramIndices(s, p);

    cout << "Anagram indices: ";
    for (int index : indices)
        cout << index << " ";
    cout << endl;

    return 0;
}
