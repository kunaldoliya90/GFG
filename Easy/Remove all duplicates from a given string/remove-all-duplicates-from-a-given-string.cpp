//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	    int n = str.size();
	    unordered_set < char > ansMap;
	    string result;
	    for (char c : str) {
        if (ansMap.find(c) == ansMap.end()) {
            result += c;
            ansMap.insert(c);
        }
    }
    return result;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends