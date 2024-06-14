//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n) {
        int sum = 0;
        vector<int> vc;
        int x = n;
        while(x > 0){
            int digit = x % 10;
            vc.push_back(digit);
            x = x / 10;
        }
        for(int i=0; i<vc.size(); i++){
            sum += pow(vc[i], 3);
        }
        // for(int i=0; i<vc.size(); i++){
        //     cout<<vc[i]<<" ";
        // }
        if(sum == n){
            return "true";
        }else {
            return "false";
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends