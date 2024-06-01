//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        // code here
        int n = s.size();
        map<char,int> m;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            m[s[i]]++;
        }
        for(auto x:m)
        {
            if((x.first - 'a' + 1)%2)
            {
                if(x.second%2)
                {
                    ans++;
                }
            }
            else
            {
                if(x.second%2==0)
                {
                    ans++;
                }
            }
        }
        if(ans%2)
        {
            return "ODD";
        }
        else
        {
            return "EVEN";
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends