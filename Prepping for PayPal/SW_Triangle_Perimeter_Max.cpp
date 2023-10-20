#include <bits/stdc++.h> 
int maxPerimeterTriangle(vector<int>& arr, int n) {
    // Write your code here.
    sort(arr.begin(), arr.end());
    int ans = 0;
    
    int a = arr[n-1], b = arr[n-2], c = arr[n-3];
    if(b + c > a){
        return a + b + c;
    }

    int i = n-4;
    while(i >= 0){
        a = b;
        b = c;
        c = arr[i];

        if(b+c > a){
            return a + b + c;
        }

        i--;
    }

    return 0;
}

//TC: O(nlogn)
//SC: O(1);