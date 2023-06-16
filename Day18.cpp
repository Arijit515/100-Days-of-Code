//finding the kth largest element using QuickSelect algorithm
#include <iostream>
#include <vector>
#include <algorithm>

int partition(std::vector<int>& nums, int left, int right) {
    int pivot = nums[right];
    int i = left - 1;
    for (int j = left; j < right; ++j) {
        if (nums[j] <= pivot) {
            ++i;
            std::swap(nums[i], nums[j]);
        }
    }
    std::swap(nums[i + 1], nums[right]);
    return i + 1;
}

int quickSelect(std::vector<int>& nums, int left, int right, int k) {
    if (left == right) {
        return nums[left];
    }

    int pivotIndex = partition(nums, left, right);
    int count = pivotIndex - left + 1;

    if (count == k) {
        return nums[pivotIndex];
    } else if (count > k) {
        return quickSelect(nums, left, pivotIndex - 1, k);
    } else {
        return quickSelect(nums, pivotIndex + 1, right, k - count);
    }
}

int findKthLargest(std::vector<int>& nums, int k) {
    int n = nums.size();
    return quickSelect(nums, 0, n - 1, n - k + 1);
}

int main() {
    int n, k;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;
    std::vector<int> nums(n);

    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    std::cout << "Enter the value of k: ";
    std::cin >> k;

    int kthLargest = findKthLargest(nums, k);
    std::cout << "The " << k << "th largest element is: " << kthLargest << std::endl;

    return 0;
}
