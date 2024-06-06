//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
    long long max_sum(int a[], int n) {
        // Your code here
          long totalSum = 0;
        for (int i = 0; i < n; ++i) {
            totalSum += a[i];
        }
        
        // Calculate the initial value of the sum of i * arr[i]
        long currentValue = 0;
        for (int i = 0; i < n; ++i) {
            currentValue += (long) i * a[i];
        }
        
        // Initialize maxSum to the initial value
        long maxSum = currentValue;
        
        // Iterate to find the maximum sum using the derived relationship
        for (int i = 1; i < n; ++i) {
            currentValue = currentValue + totalSum - (long) n * a[n - i];
            maxSum = max(maxSum, currentValue);
        }
        
        return maxSum;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends