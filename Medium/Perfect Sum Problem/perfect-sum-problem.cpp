//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    int mod = 1e9+7;
	public:
	int perfectSum(int arr[], int d, int sum)
	{
        // Your code goes her
        vector<int> v;
        int zero=0;
        for(int i=0;i<d;i++){
            if(arr[i] == 0)
            {
                zero++;
            }
            else{
                v.push_back(arr[i]);
            }
        }
        int n = v.size();
        vector<vector<int>> dp(n, vector<int>(sum+1, 0));
         for(int i=0;i<n;i++)
        {
            dp[i][0] = 1;
        }
        if(sum >= v[0])
        {
            dp[0][v[0]] = 1;
        }
        for(int i = 1; i<n;i++)
        {
            for(int tar=0; tar<=sum; tar++)
            {
                 int np = dp[i-1][tar];
                int pick = 0;
                if(tar  >= arr[i])
                {
                    pick = dp[i-1][tar - arr[i]];
                }
               
                dp[i][tar]  =  (pick + np) % (mod);
            }
        }
       int final = dp[n-1][sum];
       for(int i=0;i<zero;i++)
       {
           final*=2;
       }
       return final;
        
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends