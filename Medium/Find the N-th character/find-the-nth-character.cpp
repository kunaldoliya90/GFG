//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
char nthCharacter(string s, int r, int n) {
       
        while (r--) {
        string ans = "";
        for (int i = 0; i <= n; i++) {
            if (s[i] == '1') {
                ans.push_back('1');
                ans.push_back('0');
            } else {
                ans.push_back('0');
                ans.push_back('1');
            }
        }
        s = ans;
    }
    return s[n];
    
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends