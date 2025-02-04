// // Date : 5 Feb 2025

// // 2 Sum of array

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &arr, int target)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < arr.size(); i++)    
    {
        int complement = target - arr[i];
        if (mp.find(complement) != mp.end())
        {
            return {mp[complement], i};
        }

        mp[arr[i]] = i;
    }
    return {};
}

int main()
{
    int n;
    cout << "Enter the value of n:";
    cin >> n;

    vector<int> arr(n); // Vector to store the array

    cout << "Enter the numbers in array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;

    cout << "Enter the target: ";
    cin >> target;

    vector<int> result = twoSum(arr, target);

    if (!result.empty())
    {
        cout << "Indices: " << result[0] << " " << result[1] << endl;
    }
    else
    {
        cout << "No valid pair found!" << endl;
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// vector<int> twoSum(vector<int>& arr, int target) {
//     unordered_map<int, int> mp; // Stores (number, index)

//     for (int i = 0; i < arr.size(); i++) {
//         int complement = target - arr[i];

//         // Check if complement exists in the map
//         if (mp.find(complement) != mp.end()) {
//             return {mp[complement], i}; // Return indices
//         }

//         // Store the current number and its index
//         mp[arr[i]] = i;
//     }

//     return {}; // Return empty vector if no pair found
// }

// int main() {
//     int n;
//     cout << "Enter the value of n: ";
//     cin >> n;

//     vector<int> arr(n);
//     cout << "Enter the numbers in array: ";
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     int target;
//     cout << "Enter the target: ";
//     cin >> target;

//     vector<int> result = twoSum(arr, target);

//     if (!result.empty()) {
//         cout << "Indices: " << result[0] << " " << result[1] << endl;
//     } else {
//         cout << "No valid pair found!" << endl;
//     }

//     return 0;
// }
