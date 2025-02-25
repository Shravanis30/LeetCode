// Number of Sub-arrays With Odd Sum

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int odd_count = 0, even_count = 1;
        int sum = 0, result = 0;

        for (int num : arr) {
            sum += num;
            
            if (sum % 2 == 0) {
                result = (result + odd_count) % MOD;
                even_count++;
            } else {
                result = (result + even_count) % MOD;
                odd_count++;
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    vector<int> arr1 = {1, 3, 5};
    cout << "Output: " << sol.numOfSubarrays(arr1) << endl;

    vector<int> arr2 = {2, 4, 6};
    cout << "Output: " << sol.numOfSubarrays(arr2) << endl; 

    vector<int> arr3 = {1, 2, 3, 4, 5, 6, 7};
    cout << "Output: " << sol.numOfSubarrays(arr3) << endl;

    return 0;
}
