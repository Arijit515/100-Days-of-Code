//two sum problem
#include <iostream>

using namespace std;

int main() {
  int n;
  cout << "Enter the number of elements in the array: ";
  cin >> n;

  int array[n];
  cout << "Enter the elements of the array: ";
  for (int i = 0; i < n; i++) {
    cin >> array[i];
  }

  int target;
  cout << "Enter the target sum: ";
  cin >> target;

  int indices[2];
  bool found = false;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (array[i] + array[j] == target) {
        indices[0] = i;
        indices[1] = j;
        found = true;
        break;
      }
    }
    if (found) {
      break;
    }
  }

  if (found) {
    cout << "The indices of the two numbers that add up to the target are " << indices[0] << " and " << indices[1] << endl;
  } else {
    cout << "No two numbers in the array add up to the target" << endl;
  }

  return 0;
}