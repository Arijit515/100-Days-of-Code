//to find the contiguous subarray with the largest sum and return it's sum and print the subarray
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
  int* arr;
  int max_sum = INT_MIN;
  int start_index = -1;
  int end_index = -1;

  cout << "Enter the size of the array: ";
  cin >> n;
  
  arr = new int[n];

  for (int i = 0; i < n; i++) {
    cout << "Enter the element at index " << i << ": ";
    cin >> arr[i];
  }

  for (int i = 0; i < n; i++) {
    int current_sum = 0;
    for (int j = i; j < n; j++) {
      current_sum += arr[j];
      if (current_sum > max_sum) {
        max_sum = current_sum;
        start_index = i;
        end_index = j;
      }
    }
    } 
    cout << "The largest sum contiguous subarray is: ";
  for (int i = start_index; i <= end_index; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  cout << "The sum of the subarray is: " << max_sum << endl;
  delete[] arr;
  return 0;
}