//Binary Search

#include <iostream>
#include <vector>

int search(const std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    std::vector<int> nums;
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    std::cout << "Enter the elements in ascending order:\n";
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        nums.push_back(num);
    }

    int target;
    std::cout << "Enter the target number: ";
    std::cin >> target;

    int index = search(nums, target);

    if (index != -1) {
        std::cout << "Target found at index: " << index << std::endl;
    } else {
        std::cout << "Target not found in the array." << std::endl;
    }

    return 0;
}
