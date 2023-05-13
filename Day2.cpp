//to find the kth smallest element in an array in linear time complexity

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int kthSmallest(vector<int> &arr, int n, int k) {
priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());
for (int i = 0; i < k - 1; i++) {
    pq.pop();
  }
return pq.top();
}
int main() {

int n;
cout << "Enter the size of the array: ";
cin >> n;

vector<int> arr(n);
for (int i = 0; i < n; i++) {
    cout << "Enter the element at index " << i << ": ";
    cin >> arr[i];
  }
  int k;
  cout << "Enter the value of k: ";
  cin >> k;
  cout << "The kth smallest element is " << kthSmallest(arr, n, k) << endl;

return 0;
}