//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    bool isPossible(vector<int>& stalls, int n, int k, int mid){
        int j = 0, i = 0, count = 1;
        while(i < n){
            if(stalls[i] - stalls[j] >= mid){
                count++;
                if(count == k){
                    return true;
                }
                
                j = i;
            }
            else{
                i++;
            }
        }
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(), stalls.end());
        int l = 0, r = stalls[n-1];
        int ans = stalls[0];
        while(l <= r){
            int mid = l + (r - l)/2;
            if(isPossible(stalls, n, k, mid)){
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends

//TC: O(nlogn);
//SC: O(n);