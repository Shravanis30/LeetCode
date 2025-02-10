// 10 Feb 2025

// 3174. Clear Digits

#include <iostream>
#include <stack>
#include <algorithm> 

using namespace std;

class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        
        for (char c : s) {
            if (isdigit(c)) {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(c); 
            }
        }

        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution sol;
    string userInput;
    
    cout << "Enter a string: ";
    cin >> userInput;

    string result = sol.clearDigits(userInput);
    cout << "Output: " << result << endl;

    return 0;
}
