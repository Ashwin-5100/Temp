//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& v) {
        // code here
        int n = v.size();
        int low = 0;
        int high = n-1;
        int mid = 0;
        while(mid<=high)
        {
            if(v[mid] == 0)
            {
                swap(v[low], v[mid]);
                mid++;
                low++;
            }
            else if(v[mid] == 2)
            {
                swap(v[mid], v[high]);
                high--;
            }   
            else
            {
                mid++;
            }
        }
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends