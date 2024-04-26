//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        int pos = 0, i = 0, j = 0, pi = -1, pj = -1;
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        while(0 <= i and i < n and 0 <= j and j < m){
            if(matrix[i][j]) matrix[i][j] = 0, pos = (pos + 1) % 4;
            pi = i, pj = j, i += dx[pos], j += dy[pos];
        }
        return {pi, pj};
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends