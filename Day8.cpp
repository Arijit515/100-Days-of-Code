//Max water capacity problem
#include <vector>
#include <algorithm>

int maxArea(const std::vector<int>& height) {
    int n = height.size();
    int left = 0, right = n - 1;
    int maxArea = 0;

    while (left < right) {
        int currentArea = std::min(height[left], height[right]) * (right - left);
        maxArea = std::max(maxArea, currentArea);

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxArea;
}
