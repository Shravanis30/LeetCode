#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int left = 0, maxLength = 0;

        for (int right = 0; right < s.size(); right++) {
            while (charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]);
                left++;
            }
            charSet.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};

int main() {
    Solution solution;
    string s;
    
    cout << "Enter a string: ";
    cin >> s;
    
    int result = solution.lengthOfLongestSubstring(s);
    
    cout << "Length of the longest substring without repeating characters: " << result << endl;
    
    return 0;
}
