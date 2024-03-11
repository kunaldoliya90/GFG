//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
    {
        int count=0;
      int i=0,j=0,k=n-1,l=n-1;
       while(i<n && j<n){
           int val=mat1[i][j];
           while(k>=0 && l>=0){
               int val2=mat2[k][l];
               if(val+val2>x){
                   l--;
                   if(l<0){
                       k--;
                       l=n-1;
                   }
               }
               else if(val+val2<x){
                   break;
               }
               else{
                   count++;
                   l--;
                   if(l<0){
                       k--;
                       l=n-1;
                   }
                   break;
               }
           }
           j++;
           if(j==n){
               i++;
               j=0;
           }
       }
        return count;
    }
};

//{ Driver Code Starts.


int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<vector<int>> mat1(n, vector<int>(n, -1));
        vector<vector<int>> mat2(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat1[i][j];
        	}
        }

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat2[i][j];
        	}
        }

        Solution ob;

        cout << ob.countPairs(mat1, mat2, n, x) << "\n";

    }

    return 0;
}
// } Driver Code Ends