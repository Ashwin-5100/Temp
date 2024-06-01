//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string s)
    {
       //Your code here
       int n = s.size();
       map<char,pair<int,int>> m;
       vector<pair<int,char>> v;
       for(int i=0;i<n;i++){
           m[s[i]].first++;
           m[s[i]].second = i;
       }
       for(auto x:m)
       {
           if(x.second.first==1)
           {
               v.push_back({x.second.second,x.first});
           }
       }
       if(v.size()==0)
       {
           return '$';
       }
       sort(v.begin(),v.end());
       return v[0].second;
    }

};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends