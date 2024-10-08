//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        // code here
        long long d=1;
        int f=0;
        int c=0;
        int ind = -1;
        int n = nums.size();
        vector<long long> ans(n);
        for(int i=0;i<n;i++)
        {
            if(nums[i] == 0 && c==0)
            {
                ind = i;
                f=1;
                c++;
                 continue;
            }
            if(nums[i] == 0)
            {
                c++;
                continue;
            }
              d*=nums[i];
        }
        // cout << c
        if(f)
        {
            if(c==1)
            {
                ans[ind] = d;
            }
            return ans;
        }
        for(int i=0;i<n;i++)
        {
            ans[i] = d/nums[i];
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends