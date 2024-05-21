//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        // code here
        map<int,vector<int>> mp;
        vector<int> ans;
        sort(arr.begin(),arr.end());
        for(int i=arr.size()-1;i>=0;i--){
            if(abs(arr[i]-x)==0){continue;}
            mp[abs(arr[i]-x)].push_back(arr[i]);
        }
        for(auto it:mp){
            if(k>0 && it.second.size()>=1){
                ans.push_back((it.second)[0]);
                k--;
            }
            if(k>0 && it.second.size()>=2){
                ans.push_back((it.second)[1]);
                k--;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends