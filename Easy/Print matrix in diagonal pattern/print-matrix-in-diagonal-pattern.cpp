//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
        vector<int>ans;
        int i=0,j=0;
        int n=mat.size(),m=mat[0].size();
        while(i<n and j<m){
            ans.push_back(mat[i][j]);
            //right or down move
            if(i==n-1 and j==m-1) break;
            if(j+1<m){
                j++;
            }
            else if(i+1<n) i++;
            // diagonally downward
            while(i+1<n and j-1>=0){
                ans.push_back(mat[i++][j--]);
            }
            ans.push_back(mat[i][j]);
            //down or right
            if(i+1<n) i++;
            else if(j+1<m) j++;
            //diagonally upward
            while(i-1>=0 and j+1<m){
                ans.push_back(mat[i--][j++]);
            }
        }
        return ans;
            
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends