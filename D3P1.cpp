// 07 Feb 2025

// 3160. Find the Number of Distinct Colors Among the Balls

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ball_colors;  
        unordered_map<int, int> color_count;  
        vector<int> result;
        int distinct_count = 0;  

        for (auto& query : queries) {
            int ball = query[0];
            int color = query[1];

            // Check if the ball already has a color
            if (ball_colors.count(ball)) {
                int prev_color = ball_colors[ball];
                color_count[prev_color]--;
                if (color_count[prev_color] == 0) {
                    distinct_count--; 
                }
            }

            // Assign new color to the ball
            ball_colors[ball] = color;
            if (color_count[color] == 0) {
                distinct_count++;  // New distinct color found
            }
            color_count[color]++;

            // Store the result
            result.push_back(distinct_count);
        }

        return result;
    }
};

// Main function to test the Solution class
int main() {
    Solution sol;
    int limit = 4;
    vector<vector<int>> queries = {{1, 4}, {2, 5}, {1, 3}, {3, 4}};
    
    vector<int> result = sol.queryResults(limit, queries);

    // Print the output
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
