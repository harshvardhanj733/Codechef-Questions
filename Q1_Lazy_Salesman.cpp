// Problem Code: HOLIDAYS

// Problem
// Ved is a salesman. He needs to earn at least 
// �
// W rupees in 
// �
// N days for his livelihood. However, on a given day 
// �
// i (
// 1
// ≤
// �
// ≤
// �
// 1≤i≤N), he can only earn 
// �
// �
// A 
// i
// ​
//   rupees by working on that day.

// Ved, being a lazy salesman, wants to take as many holidays as possible. It is known that on a holiday, Ved does not work and thus does not earn anything. Help maximize the number of days on which Ved can take a holiday.

// It is guaranteed that Ved can always earn at least 
// �
// W rupees by working on all days.

#include <iostream>

using namespace std;

void merge(int arr2[], int low, int mid, int high){
    int arr3[100];
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

void mergeSort(int arr2[], int low, int high){
    int mid;
    if(low<high){
        mid = (low+high)/2;
        mergeSort(arr2, low, mid);
        mergeSort(arr2, mid+1, high);
        merge(arr2, low, mid, high);
    }
}

int main(){
    
    int t, arr[101];
	cin>>t;
	for(int i = 0; i<t; i++){
	    int n, w, arr2[101];
	    cin>>n>>w;
	    for(int j = 0; j<n; j++){
	        cin>>arr2[j];
	    }
        mergeSort(arr2, 0, n-1);
        int count = 0, index = n-1;
        while(w>0){
            w -= arr2[index];
            index--; count++;
        }
        int res = n - count;
        arr[i] = res;
    }
    for(int i = 0; i<t; i++){
        cout<<arr[i]<<endl;
    }

return 0;
}

