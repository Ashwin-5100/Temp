//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void bfs(int n, vector<int> adj[], vector<int> &vis)
    {
        queue<int> q;
        q.push(n);
        vis[n] = 1;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto x:adj[node])
            {
                if(!vis[x])
                {
                    q.push(x);
                    vis[x]  = 1;
                }
            }
        }
    }
    int numProvinces(vector<vector<int>> v, int n) {
        // code here
        vector<int> adj[n+1];
        vector<int> vis(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j] == 1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                bfs(i, adj, vis);
                ans++;
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
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends