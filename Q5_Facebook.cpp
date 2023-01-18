// Facebook
// Problem Code: FACEBOOK

// Problem
// A post on facebook is said to be more popular if the number of likes on the post is strictly greater than the number of likes on some other post. In case the number of likes is same, the post having more comments is more popular.

// Given arrays 
// �
// A and 
// �
// B, each having size 
// �
// N, such that the number of likes and comments on the 
// �
// �
// ℎ
// i 
// th
//   post are 
// �
// �
// A 
// i
// ​
//   and 
// �
// �
// B 
// i
// ​
//   respectively, find out which post is most popular.

// It is guaranteed that the number of comments on all the posts is distinct.

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t, arr[1000]; // Space Complexity : O(t)
	cin>>t;
	for(int i = 0; i<t; i++){ //O(t)
	    int n, A[100000], B[100000]; // Space Complexity : O(n)
	    cin>>n;
	    int most = 0, comment = 0, index = 0;
	    for(int j = 0; j<n; j++){ //O(n)
	        cin>>A[j];
	    }
	    for(int j = 0; j<n; j++){ //O(n)
	        cin>>B[j];
	    }
	    for(int j = 0; j<n; j++){ //O(n)
	        if(A[j]>most){
	            most = A[j];
	            comment = B[j];
	            index = j+1;
	        }
	        else if(A[j] == most){
	            if(B[j]>comment){
	                most = A[j];
	                comment = B[j];
	                index = j+1;
	            }
	        }
	    }
	    arr[i] = index;
	}
	for(int i = 0; i<t; i++){ //O(t)
	    cout<<arr[i]<<endl;
	}
	return 0;
}

//Total Time Complexity : O(tn);
//Total Space Complexity : O(tn);