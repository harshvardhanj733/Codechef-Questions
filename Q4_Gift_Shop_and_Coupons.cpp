// Gift Shop and Coupon
// Problem Code: GFTSHP

// Problem
// Chef wants to impress Chefina by giving her the maximum number of gifts possible.

// Chef is in a gift shop having 
// �
// N items where the cost of the 
// �
// �
// ℎ
// i 
// th
//   item is equal to 
// �
// �
// A 
// i
// ​
//  . Chef has 
// �
// K amount of money and a 
// 50
// %
// 50% off discount coupon that he can use for at most one of the items he buys.

// If the cost of an item is equal to 
// �
// X, then, after applying the coupon on that item, Chef only has to pay 
// ⌈
// �
// 2
// ⌉
// ⌈ 
// 2
// X
// ​
//  ⌉ (rounded up to the nearest integer) amount for that item.

// Help Chef find the maximum number of items he can buy with 
// �
// K amount of money and a 
// 50
// %
// 50% discount coupon given that he can use the coupon on at most one item.

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

long roundUp(long num){
    if(num%2 == 0){
        return num/2;
    }
    return num/2 + 1;
}

int main() {
	// your code goes here
	int t, arr[1000];
	cin>>t;
	for(int i = 0; i<t; i++){ //O(t)
	    int n; long k, arr2[100000];
	    cin>>n>>k;
	    for(int j = 0; j<n; j++){
	        cin>>arr2[j];
	    } //O(n);
	    mergeSort(arr2, 0, n-1); //O(nlogn)
	    int count = 0; long sum = 0;
	   for(int j = 0; j<n; j++){
	       if(sum <= k){
	           sum += arr2[j];
	           count++;
	       }
	       else{
	           break;
	       }
	   } //(n)
	    sum -= arr2[count-1];
	    if(sum + roundUp(arr2[count-1]) <= k){
	        arr[i] = count;
	    }
	    else{
	        arr[i] = count - 1;
	    }
	}
	for(int i = 0; i<t; i++){
	    cout<<arr[i]<<endl;
	} //O(t)
	return 0;
}

// Total Time Complexity : O(tnlogn)
// Total Space Complexity : O(n)
