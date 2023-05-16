//sort 0s, 1s and 2s

#include <iostream>

using namespace std;

void sort_012(int array[], int n) {
  int low = 0;
  int high = n - 1;
  int mid = 0;

  while (mid <= high) {
    switch (array[mid]) {
      case 0:
        int temp = array[mid];
        array[mid] = array[low];
        array[low] = temp;
        mid++;
        low++;
        break;
      case 1:
        mid++;
        break;
      case 2:
        temp = array[mid];
        array[mid] = array[high];
        array[high] = temp;
        high--;
        break;
    }
  }
}

int main() {
  int n;
  cout << "Enter the number of elements in the array: ";
  cin >> n;

  int array[n];
  cout << "Enter the elements of the array: ";
  for (int i = 0; i < n; i++) {
    cin >> array[i];
  }

  sort_012(array, n);

  cout << "The sorted array is: ";
  for (int i = 0; i < n; i++) {
    cout << array[i] << " ";
  }

  cout << endl;

  return 0;
}