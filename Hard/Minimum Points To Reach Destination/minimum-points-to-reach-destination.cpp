//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
int solve(int i, int j, int m, int n, vector<vector<int>> &points, vector<vector<int>> &dp)
    {
         
        if(i == m-1 && j == n-1)
            return 1 - points[i][j];
        if(i == m || j == n)
            return INT_MAX;
        if(dp[i][j] != -1)
            return dp[i][j];
        int right = solve(i+1, j, m, n, points, dp);
        int left  = solve(i, j+1, m, n, points, dp);
        return dp[i][j] = max(1, min(right, left) - points[i][j]);
        
    }
    int minPoints(int m, int n, vector<vector<int>> points) 
    { 
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return solve(0, 0, m, n, points, dp);
    } 


};


//{ Driver Code Starts.
int main() 
{
   
   	int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> a(m, vector<int>(n));

        for(int i = 0; i < m; i++)
        	for(int j = 0; j < n; j++)
        		cin >> a[i][j];

        

	    Solution ob;
	    cout << ob.minPoints(m,n,a) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends