// 873. Length of Longest Fibonacci Subsequence
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> index;  // Stores index of each number
        unordered_map<int, int> dp;  // Key: (i, j) -> value: length of Fibonacci sequence
        int maxLen = 0;

        for (int i = 0; i < n; ++i) {
            index[arr[i]] = i;  // Map number to its index
        }

        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < j; ++i) {
                int prev = arr[j] - arr[i];
                if (prev < arr[i] && index.count(prev)) {
                    int k = index[prev];
                    int length = dp[k * n + i] + 1;
                    dp[i * n + j] = length;
                    maxLen = max(maxLen, length + 2);
                }
            }
        }

        return maxLen >= 3 ? maxLen : 0;
    }
};

int main() {
    Solution sol;
    
    vector<int> arr1 = {1,2,3,4,5,6,7,8};
    cout << "Output: " << sol.lenLongestFibSubseq(arr1) << endl;  // Expected: 5

    vector<int> arr2 = {1,3,7,11,12,14,18};
    cout << "Output: " << sol.lenLongestFibSubseq(arr2) << endl;  // Expected: 3

    return 0;
}
