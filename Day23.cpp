//combination of sums
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrack(vector<vector<int>>& result, vector<int>& combination, vector<int>& candidates, int target, int start) {
    if (target < 0) {
        return;
    } else if (target == 0) {
        result.push_back(combination);
        return;
    } else {
        for (int i = start; i < candidates.size(); i++) {
           
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            
            combination.push_back(candidates[i]);
            backtrack(result, combination, candidates, target - candidates[i], i + 1);
            combination.pop_back();
        }
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> combination;
    
    sort(candidates.begin(), candidates.end());
    
    backtrack(result, combination, candidates, target, 0);
    
    return result;
}

int main() {
    int numCandidates;
    cout << "Enter the number of candidates: ";
    cin >> numCandidates;
    
    vector<int> candidates(numCandidates);
    cout << "Enter the candidate numbers: ";
    for (int i = 0; i < numCandidates; i++) {
        cin >> candidates[i];
    }
    
    int target;
    cout << "Enter the target number: ";
    cin >> target;
    
    vector<vector<int>> combinations = combinationSum2(candidates, target);
    
    cout << "Unique combinations that sum up to " << target << ":" << endl;
    for (const auto& combination : combinations) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
