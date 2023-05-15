//best time to buy and sell stocks

#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  int* arr;
  int max_profit = INT_MIN;
  int buy_at_price = INT_MAX;
  int sell_at_price = INT_MIN;
  int buy_at_index = -1;
  int sell_at_index = -1;

  cout << "Enter the size of the array: ";
  cin >> n;
  
  arr = new int[n];

  for (int i = 0; i < n; i++) {
    cout << "Enter the element at index " << i << ": ";
    cin >> arr[i];
  }

  for (int i = 0; i < n; i++) {
    if (arr[i] < buy_at_price) {
      buy_at_price = arr[i];
      buy_at_index = i;
    }
    if (arr[i] > sell_at_price) {
      sell_at_price = arr[i];
      sell_at_index = i;
    }
    if (sell_at_index > buy_at_index) {
      max_profit = max(max_profit, sell_at_price - buy_at_price);
    }
  }
  cout << "The maximum profit is: " << max_profit << endl;
  delete[] arr;
  return 0;
}
