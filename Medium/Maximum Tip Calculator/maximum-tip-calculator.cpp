//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &a, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        // code here
        long long ans = 0;
        priority_queue<pair<int,int>> pq;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq2;
        
        for(int i=0; i<n; i++){
            pq.push({arr[i]-brr[i], i});
        }
        while(!pq.empty() && pq.top().first >= 0 && x--){
            ans += arr[pq.top().second];
            pq.pop();
        }
        while(!pq.empty()){
            pq2.push(pq.top());
            pq.pop();
        }
        while(!pq2.empty() && y--){
            ans += brr[pq2.top().second];
            pq2.pop();
        }
        while(!pq2.empty() && x--){
            ans += arr[pq2.top().second];
            pq2.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    }
}

// } Driver Code Ends