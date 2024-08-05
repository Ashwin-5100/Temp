//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
  public:
    int isValid(string str) {
        // code here 
        int i=0;
        int n=str.size();
        int count=0;
        while(i<n){
            string temp="";
            while(i<n && str[i]!='.'){
                temp+=str[i++];
            }
            if(str[i]=='.'){
                i++;
                count++;
            }
            if(temp.size()==0 or stoi(temp)>255 or (stoi(temp)!=0 && temp[0]=='0')) return 0;
        }
        if(count==3) return 1;
        return 0;

    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends