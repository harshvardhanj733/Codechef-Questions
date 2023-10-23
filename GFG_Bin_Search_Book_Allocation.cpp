//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    int isPossible(int A[], int N, int M, int mid){
        int count = 1;
        long sum = 0;
        int i = 0;
        while(i < N){
            if(sum + A[i] <= mid){
                sum += A[i];
                i++;
            }
            else{
                count++;
                if(count > M){
                    return false;
                }
                sum = 0;
            }
        }
        return true;
    }
    
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        
        if(N < M){
            return -1;
        }
        
        long int sum = 0;
        for(int i = 0; i < N; i++){
            sum += 1L*A[i];
        }
        
        long int l = 0, r = sum, ans = sum;
        
        while(l <= r){
            long int mid = l + (r - l)/2;
            if(isPossible(A, N, M, mid)){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        
        return (int)ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

//TC: O(nlogn);
//SC: O(1);

// } Driver Code Ends