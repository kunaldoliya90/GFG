//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    int remove_duplicate(int a[],int n){
         if (n == 0 || n == 1) // Base case: if array has 0 or 1 element, no duplicates to remove
        return n;

    int lastDistinctIndex = 0; // Index to store the last position where a distinct element was found

    // Traverse the array starting from the second element
    for (int i = 1; i < n; i++) {
        // If the current element is different from the previous distinct element
        if (a[i] != a[lastDistinctIndex]) {
            lastDistinctIndex++; // Move to the next position
            a[lastDistinctIndex] = a[i]; // Copy the current element to the next position
        }
    }

    // Return the size of the modified array containing only distinct elements
    return lastDistinctIndex + 1;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int a[N];
        for(int i=0;i<N;i++)
        {
            cin>>a[i];
        }
    Solution ob;
    int n = ob.remove_duplicate(a,N);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    }
}
// } Driver Code Ends