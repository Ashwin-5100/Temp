//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
  
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<pair<int,int>> adj[V];
            vector<int> indegree(V,0);
        for(int i=0;i<E;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
            indegree[v]++;
        }
    
        queue<int> q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        stack<int> topo;
        vector<int> ans;
        vector<int> vis(V,0);
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            ans.push_back(front);
            for(auto x:adj[front])
            {
                indegree[x.first]-=1;
                if(indegree[x.first] == 0)
                {
                    q.push(x.first);
                }
            }
        }
        reverse(ans.begin(), ans.end());
        for(auto x:ans)
        {
            topo.push(x);
        }
        vector<int> dist(V,1e9);
        dist[0] = 0;
        while(!topo.empty())
        {
            int top = topo.top();
            topo.pop();
            for(auto x: adj[top])
            {
                int v = x.first;
                int wt = x.second;
                if(wt + dist[top] < dist[v])
                {
                    dist[v] = wt + dist[top];
                }
            }
        }
        for(int i=0;i<V;i++)
        {
            if(dist[i] == 1e9)
            {
                dist[i] = -1;
            }
        }
        return dist;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends