//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(int i,vector<vector<int>> &adj, vector<int> &vis)
    {
        int n = adj.size();
        vis[i] = 1;
        queue<pair<int,int>> q;
        q.push({i,-1});
        while(!q.empty())
        {
           int node = q.front().first;
           int par = q.front().second;
            q.pop();
            for(auto x: adj[node])
            {
                if(vis[x] != 1)
                {
                    vis[x] = 1;
                    q.push({x, node});   
                }
                else if(x!=par)
                {
                    return 1;
                }
            }
        }
        return 0;
        
    }
    
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> vis(n);
        for(int i=0;i<n;i++)
        {
            if(vis[i] == 0)
            {
                
                if(bfs(i, adj, vis))
                {
                    return 1;
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends