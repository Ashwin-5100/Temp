//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &path)
    {
        vis[node] = 1;
        path[node] = 1;
        for(auto x:adj[node])
        {
            if(!vis[x])
            {
                if(dfs(x, adj, vis, path))
                {
                    return 1;
                }
            }
            else if(path[x])
            {
                return 1;
            }
        }
        path[node] = 0;
        return 0;
    }
    
  public:
    // Function to detect cycle in a directed graph.
    
    bool isCyclic(vector<vector<int>> &adj) {
        // code here
       int n = adj.size();
        vector<int> ans;
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto j:adj[i])
            {
                indegree[j]++;
            }
        }
        
        vector<int> vis(n,0);
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int front  = q.front();
            q.pop();
            ans.push_back(front);
            for(auto x:adj[front]){
                indegree[x]--;
                if(indegree[x]==0)
                {
                    q.push(x);
                }
            }
        }
        if(ans.size() == n)
        {
            return 0;
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends