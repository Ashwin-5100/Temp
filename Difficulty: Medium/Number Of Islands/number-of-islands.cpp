//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class DSU {
    vector<int> rank, parent, size;
  public:
    DSU(int n)
    {
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    }
    
    int findparent(int node)
    {
        if(parent[node] == node)
        {
            return node;
        }
        return parent[node] = findparent(parent[node]);
    }
    
    void unionbyrank(int u, int v)
    {
        int parent_u = findparent(u);
        int parent_v = findparent(v);
        
        if(rank[parent_u] < rank[parent_v])
        {
            parent[parent_u] = parent_v;
        }
        else if(rank[parent_u] > rank[parent_v])
        {
            parent[parent_v] = parent_u;
        }
        else
        {
              parent[parent_v] = parent_u;
             rank[parent_u]++;
        }
    }
};


class Solution {
  public:
  
  bool check(int x, int y, int n, int m)
  {
      if(x>=0 && y>=0 && x<n && y<m)
      {
          return 1;
      }
      
      return 0;
  }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &v) {
        // code here
        DSU d(n*m);
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<int> ans;
        int k = v.size();
        int c=0;
        for(int i=0;i<k;i++)
        {
            int x = v[i][0];
            int y = v[i][1];
            
            if(vis[x][y]==1)
            {
                ans.push_back(c);
                continue;
            }
            
            vis[x][y] = 1;
            c++;
            int dx[] = {1,0,-1,0};
            int dy[] = {0,1,0,-1};
            for(int j=0;j<4;j++)
            {
                int adx = x+dx[j];
                int ady = y + dy[j];
                if(check(adx,ady,n,m))
                {
                    if(vis[adx][ady]==1)
                    {
                        int adjnode = adx*m + ady;
                        int nodenum = x*m+y;
                        if(d.findparent(nodenum)!= d.findparent(adjnode))
                        {
                            c--;
                            d.unionbyrank(nodenum, adjnode);
                        }
                    }
                }
            }
            ans.push_back(c);
        }
        
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends