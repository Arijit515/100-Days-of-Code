//median of arrays

#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();

    if (m > n) {
        
        return findMedianSortedArrays(nums2, nums1);
    }

    int left = 0, right = m, halfLen = (m + n + 1) / 2;
    while (left <= right) {
        int partitionX = (left + right) / 2;
        int partitionY = halfLen - partitionX;

        int maxLeftX = (partitionX == 0) ? INT32_MIN : nums1[partitionX - 1];
        int minRightX = (partitionX == m) ? INT32_MAX : nums1[partitionX];
        int maxLeftY = (partitionY == 0) ? INT32_MIN : nums2[partitionY - 1];
        int minRightY = (partitionY == n) ? INT32_MAX : nums2[partitionY];

        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            if ((m + n) % 2 == 0) {
                return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
            } else {
                return max(maxLeftX, maxLeftY);
            }
        } else if (maxLeftX > minRightY) {
            right = partitionX - 1;
        } else {
            left = partitionX + 1;
        }
    }

    
    throw invalid_argument("Invalid input arrays.");
}

int main() {
    int m, n;
    cout << "Enter the size of the first array (nums1): ";
    cin >> m;
    cout << "Enter the size of the second array (nums2): ";
    cin >> n;

    vector<int> nums1(m), nums2(n);

    cout << "Enter the elements of the first array (nums1): ";
    for (int i = 0; i < m; i++) {
        cin >> nums1[i];
    }

    cout << "Enter the elements of the second array (nums2): ";
    for (int i = 0; i < n; i++) {
        cin >> nums2[i];
    }

    double median = findMedianSortedArrays(nums1, nums2);
    cout << "Median: " << median << endl;

    return 0;
}
