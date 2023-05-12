//reverse an array

#include <iostream>

using namespace std;

void reverseArray(int arr[], int n) {
  for (int i = 0, j = n - 1; i < j; i++, j--) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
}

int main() {
  int n;
  cout << "Enter the size of the array: ";
  cin >> n;

  int arr[n];
  cout << "Enter the elements of the array: ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << "Original array: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  reverseArray(arr, n);

  cout << "Reversed array: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}