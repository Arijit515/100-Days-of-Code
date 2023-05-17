// missing and repeating numbers

#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  int array[n];
  for (int i = 0; i < n; i++) {
    cin >> array[i];
  }

  int missing_number = 0;
  int repeating_number = 0;

  for (int i = 0; i < n; i++) {
    int current_element = array[i];

    if (current_element > 0) {
      while (current_element > 0) {
        int index = current_element - 1;

        if (array[index] == current_element) {
          break;
        } else if (array[index] < 0) {
          swap(array[index], array[i]);
          break;
        }

        current_element = -array[index];
      }

      if (current_element > 0) {
        missing_number = current_element;
        break;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (array[i] < 0) {
      repeating_number = -array[i];
      break;
    }
  }

  cout << "Missing number = " << missing_number << endl;
  cout << "Repeating number = " << repeating_number << endl;

  return 0;
}