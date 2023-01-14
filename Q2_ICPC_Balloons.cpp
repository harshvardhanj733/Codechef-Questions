// Problem Code: BALLOON

// Problem
// Read problems statements in Mandarin Chinese, Russian, Vietnamese and Bengali as well.
// Chef is participating in an ICPC regional contest, in which there is a total of 
// �
// N problems (numbered 
// 1
// 1 through 
// �
// N) with varying difficulties. For each valid 
// �
// i, the 
// �
// i-th easiest problem is problem 
// �
// �
// A 
// i
// ​
//  .

// After a team solves a problem, a balloon with a colour representing that problem is tied next to their desk. Chef is fond of colours in VIBGYOR, which are representative of the problems with numbers 
// 1
// 1 through 
// 7
// 7. The remaining problems have their own representative colours too.

// Find the minimum number of problems which Chef's team needs to solve in order to get all the balloons for problems 
// 1
// 1 through 
// 7
// 7 (and possibly some other balloons too) tied next to their desk, if you know that Chef's team knows the difficulties of all problems and solves the problems in increasing order of difficulty.

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t, arr[10501];
	cin>>t;
	for(int i = 0; i<t; i++){
	    int n, arr1[16], index = 7, count = 0;
	    cin>>n;
	    for(int j = 0; j<n; j++){
	        cin>>arr1[j];
	        if(index!=0){count++;}
	        if(arr1[j]>=1 && arr1[j]<=7){index--;}
	    }
	    arr[i] = count;
	}
	for(int i = 0; i<t; i++){
	    cout<<arr[i]<<endl;
	}
	return 0;
}
