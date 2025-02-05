// 

#include <bits/stdc++.h>
using namespace std;

    int maxAscendingSum(vector<int>& nums) {
        int maxSum = nums[0];
        int currentSum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
            if(nums[i] > nums[i -1]) {
                currentSum +=nums[i];
            }
            else {
                currentSum = nums[i];
            }
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;

    }


int main() {

    int n;

    cout << "Enter the value of n:" << endl;
    cin >> n;

    vector<int> arr(n); // Vector to store the array

    cout << "Enter the values in array : " << endl;
    for(int i = 0; i < n; i ++) {
        cin >> arr[i];
    }

    int result = maxAscendingSum(arr);

    cout << "The Maximum Ascending Sum = " << result << endl;

    return 0;
}


// class Solution {
// public:
//         int maxSum = nums[0]; 
//         int currentSum = nums[0]; 
        
//         for (int i = 1; i < nums.size(); i++) {
//             if (nums[i] > nums[i - 1]) {
//                 currentSum += nums[i]; 
//             } else {
//                 currentSum = nums[i]; 
//             }
//             maxSum = max(maxSum, currentSum);
//         }
        
//         return maxSum;
//     }
// };