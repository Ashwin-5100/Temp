//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class DSU{
  vector<int> rank;
  vector<int> parent;
  public:
      DSU(int n)
      {
          rank.resize(n+1, 0);
          parent.resize(n+1);
          for(int i=0;i<=n;i++)
          {
              parent[i] = i;
          }
      }
      
      int findpar(int node)
      {
          if(node == parent[node])
          {
              return node;
          }
          
          return parent[node] = findpar(parent[node]);
      }
      
      void unionByrank(int u, int v)
      {
          int par_u = findpar(u);
          int par_v = findpar(v);
          if(par_u == par_v)
          {
              return;
          }
          if(rank[par_u] < rank[par_v])
          {
              parent[par_u] = par_v;
          }
          else if(rank[par_v] < rank[par_u])
          {
              parent[par_v] = par_u;
          }
          else
          {
              parent[par_v] = par_u;
              rank[par_u]++;
          }
      }
  
};


class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> edg[]) {
        // code here
        vector<pair<int, pair<int,int>>> adj;
        for(int i=0;i<V;i++)
        {
            for(auto x : edg[i])
            {   int wt = x[1];
                int u = i;
                int y = x[0];
                
                adj.push_back({wt, {u, y}});
            }
        }
        sort(adj.begin(), adj.end());
        
        DSU d(V);
        int ans=0;
        for(auto x : adj)
        {
            int u = x.second.first;
            int wt = x.first;
            int v = x.second.second;
            
            if(d.findpar(u) != d.findpar(v))
            {
                ans+=wt;
                d.unionByrank(u,v);
                
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
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends