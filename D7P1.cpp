#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) 
            return findMedianSortedArrays(nums2, nums1);  // Ensure nums1 is the smaller array

        int m = nums1.size(), n = nums2.size();
        int low = 0, high = m;

        while (low <= high) {
            int partitionX = (low + high) / 2;
            int partitionY = (m + n + 1) / 2 - partitionX;

            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == m) ? INT_MAX : nums1[partitionX];

            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == n) ? INT_MAX : nums2[partitionY];

            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                // Even length case
                if ((m + n) % 2 == 0) 
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                // Odd length case
                else 
                    return max(maxLeftX, maxLeftY);
            }
            else if (maxLeftX > minRightY) {
                high = partitionX - 1;  // Move left
            }
            else {
                low = partitionX + 1;  // Move right
            }
        }
        return 0.0;  // Should never reach here
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    
    double median = sol.findMedianSortedArrays(nums1, nums2);
    cout << "Median: " << median << endl;

    return 0;
}
