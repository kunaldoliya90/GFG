//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
       bool check(int freq[]){
            int n = -1;
            
            for(int f=0;f<26;f++){
                if(freq[f]>0){
                    if(n==-1){
                        n=freq[f];
                    }else if(freq[f]!=n) return false;
                    
                }
            }
            return true;
        }
    	bool sameFreq(string s) {
        int freq[26] = {0};
        int n = s.length();
    
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }
    
        if (check(freq)) {
            return true;
        }
    
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                freq[i]--;
                if (check(freq)) {
                    return true;
                }
                freq[i]++;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends