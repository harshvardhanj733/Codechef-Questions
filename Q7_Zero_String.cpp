// Zero String
// Problem Code: ZEROSTRING

// Problem
// You are given a Binary string 
// �
// S of length 
// �
// N. You are allowed to perform the following types of operations on string 
// �
// S:

// Delete any one character from 
// �
// S, and concatenate the remaining parts of the string. For example, if we delete the third character of 
// �
// =
// 1101
// S=1101, it becomes 
// �
// =
// 111
// S=111.
// Flip all the characters of 
// �
// S. For example, if we flip all character of 
// �
// =
// 1101
// S=1101, it becomes 
// �
// =
// 0010
// S=0010.
// Given that you can use either type of operation any number of times, find the minimum number of operations required to make all characters of the string 
// �
// S equal to 
// 0
// 0.

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t, arr[2000];
	cin>>t;
	for(int i = 0; i<t; i++){
	    int n, count0 = 0, count1 = 0;
	    cin>>n;
	    for(int j = 0; j<n; j++){
	        char c;
	        cin>>c;
	        if(c-'0' == 0){
	            count0 += 1;
	        }
	        else if(c-'0' == 1){
	            count1 += 1;
	        }
	    }
	    if(count0 == 0){
	        arr[i] = 1;
	    }
	    else if(count1 == 0){
	        arr[i] = 0;
	    }
	    else{
	        if(count0 + 1 <= count1){
	            arr[i] = count0 + 1;
	        }
	        else{
	            arr[i] = count1;
	        }
	    }
	}
	for(int i = 0; i<t; i++){
	    cout<<arr[i]<<endl;
	}
	return 0;
}

// Time Complexity : O(tn);
// Space Complexity : O(t);