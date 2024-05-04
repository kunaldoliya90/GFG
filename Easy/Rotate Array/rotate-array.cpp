//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    
    //Function to rotate an array by d elements in counter-clockwise direction. 
   void rotateArr(int arr[], int d, int n){
    d = d % n; // Adjusting d to be within the range of the array size
    int s = 0;
    int e = n-1;
    while(s < e){
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
    s = 0;
    e = n-d-1;
    while(s < e){
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
    s = n-d;
    e = n-1;
    while(s < e){
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}
};

//{ Driver Code Starts.

int main() {
	int t;
	//taking testcases
	cin >> t;
	
	while(t--){
	    int n, d;
	    
	    //input n and d
	    cin >> n >> d;
	    
	    int arr[n];
	    
	    //inserting elements in the array
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    //calling rotateArr() function
	    ob.rotateArr(arr, d,n);
	    
	    //printing the elements of the array
	    for(int i =0;i<n;i++){
	        cout << arr[i] << " ";
	    }
	    cout << endl;
	}
	return 0;
}
// } Driver Code Ends