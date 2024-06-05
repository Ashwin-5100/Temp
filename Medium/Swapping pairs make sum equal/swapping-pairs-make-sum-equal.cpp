//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
          int sum=0;
        int sum2=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
        }
        for(int j=0;j<m;j++){
            sum2+=b[j];
        }
        int diff=sum-sum2;
        if (diff % 2 != 0) {
            return -1;
        }
       
        diff /= 2;
        unordered_set<int> setB(b, b + m);

        for (int i = 0; i < n; i++) {
            if (setB.find(a[i] - diff) != setB.end()) {
                return 1; 
            }
        }

        return -1; 
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends