//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int swapNibbles(int n) {
        // code here
        bitset<8> v(n); 
        vector<int> ans(8);
        int j=0;
        for(int i=4;i<8;i++)
        {
            ans[j] = v[i];
            j++;
        }
        for(int i=0;i<4;i++)
        {
            ans[j] = v[i];
            j++;
        }
        int final=0;
        for(int i=0;i<8;i++)
        {
            final+=pow(2,i)*ans[i];
        }
        return final;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.swapNibbles(n) << endl;
    }
    return 0;
}
// } Driver Code Ends