//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisjointSet{
    public:
    vector<int>size,parent,rank;
    
    DisjointSet(int n){
        size.resize(n+1);
        rank.resize(n+1);
        parent.resize(n+1);
        
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
        
    }
    
    int findParent(int u){
        if(parent[u]==u)return u;
        return parent[u]=findParent(parent[u]);
    }
    
    void UnionBySize(int u,int v){
        int par_u=findParent(u);
        int par_v=findParent(v);
        
        if(par_u==par_v)return;
        if(size[par_u]>=size[par_v]){
            parent[par_v]=par_u;
            size[par_u]+=size[par_v];
        }
        else{
            parent[par_u]=par_v;
            size[par_v]+=size[par_u];
        }
    }
    
    void UnionByRank(int u,int v){
        int par_u=findParent(u);
        int par_v=findParent(v);
        if(par_u==par_v)return;
        
        if(rank[par_u]==rank[par_v]){
            rank[par_u]++;
            parent[par_v]=par_u;
        }
        else if(rank[par_u]>rank[par_v]){
            parent[par_v]=par_u;
            
        }
        else{
            parent[par_u]=par_v;
        }
    }
};
class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        int n=accounts.size();
        
        DisjointSet ds(n);
        
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                
                if(mp.find(accounts[i][j])==mp.end()){
                    mp[accounts[i][j]]=i;
                }
                else{
                    ds.UnionBySize(mp[accounts[i][j]],i);
                }
            }
        }
        
        vector<string>merge[n];
        for(auto it:mp){
            string mail=it.first;
            int node=ds.findParent(it.second);
            merge[node].push_back(mail);
        }
        
        vector<vector<string>>ans;
        
        for(int i=0;i<n;i++){
            if(merge[i].size()==0)continue;
            sort(merge[i].begin(),merge[i].end());
            string name=accounts[i][0];
            vector<string>temp;
            temp.push_back(name);
            for(auto it:merge[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<string>> accounts;

        for (int i = 0; i < n; i++) {
            vector<string> temp;
            int x;
            cin >> x;

            for (int j = 0; j < x; j++) {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            accounts.push_back(temp);
        }

        ///
        Solution obj;
        vector<vector<string>> res = obj.accountsMerge(accounts);
        sort(res.begin(), res.end());
        cout << "[";
        for (int i = 0; i < res.size(); ++i) {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++) {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], " << endl;
            else
                cout << "]";
        }
        cout << "]" << endl;
    }
}
// } Driver Code Ends