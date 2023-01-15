// Problem Code: CM164364

// Problem
// Read problems statements in Mandarin Chinese, Russian, and Bengali as well.
// There are 
// �
// n chocolates, and you are given an array of 
// �
// n numbers where the 
// �
// i-th number 
// �
// �
// A 
// i
// ​
//   is the flavour type of the 
// �
// i-th chocolate. Sebrina wants to eat as many different types of chocolates as possible, but she also has to save at least 
// �
// x number of chocolates for her little brother.

// Find the maximum possible number of distinct flavour types Sebrina can have.

#include <iostream>
using namespace std;

void merge(long arr2[], int low, int mid, int high){
    long arr3[200000];
    int i = low;
    int j = mid + 1;
    int k = low;
    while(i<=mid && j<=high){
        if(arr2[i] <= arr2[j]){
            arr3[k] = arr2[i];
            i++;
        }
        else{
            arr3[k] = arr2[j];
            j++;
        }
        k++;
    }
    while(i<=mid){
        arr3[k] = arr2[i];
        k++; i++;
    }
    while(j<=high){
        arr3[k] = arr2[j];
        k++; j++;
    }
    for(int m = low; m<=high; m++){
        arr2[m] = arr3[m];
    }
}

void mergeSort(long arr2[], int low, int high){
    int mid;
    if(low<high){
        mid = (low+high)/2;
        mergeSort(arr2, low, mid);
        mergeSort(arr2, mid+1, high);
        merge(arr2, low, mid, high);
    }
}

int main() {
	// your code goes here
	int t, arr[11];
	cin>>t;
	for(int i = 0; i<t; i++){
	    int n, x; long arr2[200000];
	    cin>>n>>x;
	    for(int j = 0; j<n; j++){
	        cin>>arr2[j];
	    }
	    mergeSort(arr2, 0, n-1);
	    int distinct = 0; long last = -1;
	    for(int j = 0; j<n; j++){
	        if(arr2[j] != last){
	            distinct++;
	            last = arr2[j];
	        }
	    }
	    if(n - x >= distinct){
	        arr[i] = distinct;
	    }
	    else{
	        arr[i] = n - x;
	    }
	}
	for(int i = 0; i<t; i++){
	    cout<<arr[i]<<endl;
	}
	return 0;
}
