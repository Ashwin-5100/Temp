//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// long long int maxSum(int arr[], int n);

// } Driver Code Ends
class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        // code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        long long ans = 0;
        int d = 0;
        vector<long long> v;
        int j = n-1;
        for(int i=0;i<=j;)
        {
            if(i==j)
            {
                v.push_back(arr[i]);
            }
            else
            {
                v.push_back(arr[i]);
                v.push_back(arr[j]);   
            }
            i++;
            j--;
        }
        for(int i=0;i<n-1;i++)
        {
            ans+=abs(v[i] - v[i+1]);
        }
        return ans + abs(v[0] - v[n-1]);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends