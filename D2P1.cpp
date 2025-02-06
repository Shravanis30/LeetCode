// Date 06 Feb 2025

// Check if One String Swap Can Make Strings Equal

#include <bits/stdc++.h>
using namespace std;

bool areAlmostEqual(string S1, string S2) {

    if(S1 == S2) return true;

    vector<int>diffIndices;

    for(int i = 0; i < S1.size(); i++) {
        if(S1[i] != S2[i]) {
            diffIndices.push_back(i);
        }
    }

    if(diffIndices.size() != 2) return false;

    int i = diffIndices[0], j = diffIndices[1];
    return S1[i] == S2[j] && S1[j] == S2[i]; 
}

int main() {

    string S1, S2;

    cout << "Enter the value of S1 : " << endl;
    cin >> S1;

    cout << "Enter the valur of S2 : " << endl;
    cin >> S2;

    bool result = areAlmostEqual(S1, S2);

    cout << (result ? "true" : "false") << endl;

    return 0;
}