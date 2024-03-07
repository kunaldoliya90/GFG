//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   string longestSubstring(string s, int n) {
        string ans="";
        int i=0,j=0;
        while(i<n){
            string t=s.substr(j,i-j+1);
            int x=s.find(t,i+1);
            if(x!=string::npos){
                if(t.length()>ans.size()){
                    ans=t;
                }
                i++;
            }
            else{
                j++;
            }
            if(i<j)i=j;
        }
        if(ans=="")return "-1";
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        string S;

        cin >> N;
        cin >> S;

        Solution ob;
        cout << ob.longestSubstring(S, N) << endl;
    }
    return 0;
}
// } Driver Code Ends