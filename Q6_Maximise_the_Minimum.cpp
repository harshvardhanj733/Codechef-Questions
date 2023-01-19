// Maximize the Minimum

// Problem Code: MAXTHEMIN

// JJ has an array 
// �
// A of size 
// �
// N. He can perform the following operations on the array at most 
// �
// K times:

// Set 
// �
// �
// :
// =
// �
// �
// +
// 1
// A 
// i
// ​
//  :=A 
// i+1
// ​
//   where 
// 1
// ≤
// �
// ≤
// �
// −
// 1
// 1≤i≤N−1
// Set 
// �
// �
// :
// =
// �
// �
// −
// 1
// A 
// i
// ​
//  :=A 
// i−1
// ​
//   where 
// 2
// ≤
// �
// ≤
// �
// 2≤i≤N
// He wants to maximize the value of the minimum element of the array 
// �
// A. Formally, he wants to maximize the value of 
// min
// ⁡
// 1
// ≤
// �
// ≤
// �
// �
// �
// 1≤i≤N
// min
// ​
//  A 
// i
// ​
//  .

// Can you help him do so?

#include <iostream>
using namespace std;

void merge(long arr[], int low, int mid, int high){
    int i = low, k = low, j = mid+1;
    long arrDup[100000]; //Space Complexity O(n)
    while(i<=mid && j<=high){
        if(arr[i] < arr[j]){
            arrDup[k] = arr[i];
            i++;
        }
        else{
            arrDup[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i<=mid){
        arrDup[k] = arr[i];
        i++; k++;
    }
    while(j<=high){
        arrDup[k] = arr[j];
        j++; k++;
    }
    for(int m = low; m<=high; m++){
        arr[m] = arrDup[m];
    }
}

void mergeSort(long arr[], int low, int high){
    int mid;
    if(low<high){
        mid = (low+high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}


int main() {
	// your code goes here
	int t; long arr[100]; //Space Complexity : O(t)
	cin>>t;
	for(int i = 0; i<t; i++){ //O(t)
	    int n, k; long arr2[100000];
	    cin>>n>>k;
	    long max = 0;
	    for(int j = 0; j<n; j++){ //O(n)
	        cin>>arr2[j];
	        if(arr2[j]>max){
	            max = arr2[j];
	        }
	    }
	    if(n<=k+1){
	        arr[i] = max;
	    }
	    else{
	        mergeSort(arr2, 0, n-1); //O(nlogn)
	        arr[i] = arr2[k];
	    }
	}
	for(int i = 0; i<t; i++){ //O(t)
	    cout<<arr[i]<<endl;
	}
	return 0;
}

// Total Time Complexity : O(tnlogn)
// Total Space Complexity : O(tn)
