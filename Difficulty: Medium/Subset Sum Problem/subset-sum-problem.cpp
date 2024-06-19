//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int dp[105][10100];
    int rec(int level, int tar,int n, int sum, vector<int> v)
    {
        if(tar>sum)
        {
            return 0;
        }
        if(level==n)
        {
            if(tar==sum)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        if(dp[level][tar]!=-1)
        {
            return dp[level][tar];
        }
        int ans=0;
        if(rec(level+1, tar, n, sum, v))
        {
            ans=1;
        }
        else if(rec(level+1, tar+v[level], n, sum, v))
        {
            ans=1;
        }
         dp[level][tar] = ans;
         return ans;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here
        memset(dp,-1,sizeof(dp));
        int n = arr.size();
        
       return rec(0,0,n, sum, arr);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends