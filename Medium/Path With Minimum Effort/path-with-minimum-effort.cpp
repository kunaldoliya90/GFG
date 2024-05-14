//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        // code here
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>> pq;
        int r = heights.size();
        int c= heights[0].size();
        vector<vector<int>>dist(r,vector<int>(c,INT_MAX));
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            int diff = temp.first;
            int row = temp.second.first;
            int col = temp.second.second;
            if(row == r-1 and col == c-1) return diff;
            if(row>0){
                int newEffort = max(abs(heights[row][col] - heights[row-1][col] ), diff);
                if(newEffort<dist[row-1][col]){
                    dist[row-1][col] = newEffort;
                    pq.push({newEffort,{row-1,col}});
                }
            }
            if(col>0){
                int newEffort = max(abs(heights[row][col] - heights[row][col-1] ), diff);
                if(newEffort<dist[row][col-1]){
                    dist[row][col-1] = newEffort;
                    pq.push({newEffort,{row,col-1}});
                }
            }
            if(row<r-1){
                int newEffort = max(abs(heights[row][col] - heights[row+1][col] ), diff);
                if(newEffort<dist[row+1][col]){
                    dist[row+1][col] = newEffort;
                    pq.push({newEffort,{row+1,col}});
                }
            }
            if(col<c-1){
                int newEffort = max(abs(heights[row][col] - heights[row][col+1] ), diff);
                if(newEffort<dist[row][col+1]){
                    dist[row][col+1] = newEffort;
                    pq.push({newEffort,{row,col+1}});
                }
            }
        }
        return 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends