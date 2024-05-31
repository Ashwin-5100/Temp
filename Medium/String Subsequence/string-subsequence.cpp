//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countWays(string s1, string s2) {
        // code here
        int n = s1.size();
        int mod = 1e9+7;
        int m=s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        for(int i=0;i<=n;i++)
        {
            dp[i][m] = 1;
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j = m-1; j>=0; j--)
            {
                int pick =0;
                if(s1[i] == s2[j])
                {
                   pick = dp[i+1][j+1];
                }
                int np = dp[i+1][j];
                dp[i][j] = (pick + np)%mod;
            }
        }
        return dp[0][0];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends