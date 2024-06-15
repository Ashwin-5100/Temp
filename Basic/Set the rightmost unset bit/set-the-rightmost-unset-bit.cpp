//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int setBit(int N)
    {
        // Write Your Code here
        int ans=-1;
        for(int i=0;i<32;i++)
        {
            if(!((1<<i) & N))
            {
                ans = i;
                break;
            }
        }
        if(ans==-1)
        {
            return N;
        }
        N = N | 1<<ans;
        return  N;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        int ans = ob.setBit(N);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends