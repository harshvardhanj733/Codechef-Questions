#include<iostream>
#include<bits/stdc++.h>

using namespace std;

pair<int, int> diffPair(int* arr, int n, int diff){
    sort(arr, arr+n);
    int i = 0, j = 1;
    while(i < j && j < n){
        if(arr[j] - arr[i] == diff){
            pair<int, int> p;
            p.first = arr[i];
            p.second = arr[j];
            return p;
        }
        if(arr[j] - arr[i] < diff){
            j++;
        }
        else{
            i++;
        }
    }
    pair<int, int>p;
    p.first = -1;
    p.second = -1;
    return p;
}

int main(){
    int n, diff;
    cin>>n>>diff;
    int * arr = new int[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    cout<<diffPair(arr, n, diff).first<< " "<<diffPair(arr, n, diff).second<<endl;
}