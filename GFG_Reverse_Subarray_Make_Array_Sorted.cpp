#include <bits/stdc++.h> 
bool sortArr(int n, vector<int> &arr){
    // Write your code here.
    if(arr.size() == 1){
        return true;
    }

    int i = 0;
    while(i < n-1 && arr[i] <= arr[i+1]){
        i++;
    }
    if(i == n-1){
        return true;
    }

    int startIndex = i;
    while(i < n-1 && arr[i] >= arr[i+1]){
        i++;
    }
    int endIndex = i;

    // reverse(arr.begin() + startIndex, arr.begin() + endIndex);
    int j = endIndex;
    i = startIndex;
    while(i < j){
        swap(arr[i], arr[j]);
        i++; j--;
    }

    for(int i = 0; i < arr.size()-1; i++){
        if(arr[i] > arr[i+1]){
            return false;
        }
    }
    return true;
}