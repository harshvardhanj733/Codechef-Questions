#include<unordered_map>
int subarraysWithSumK(vector < int > a, int b) {
    // Write your code here
    unordered_map<int, int> m;
    m[0] = 1;
    int xr = 0, ans = 0;
    for(int i = 0; i < a.size(); i++){
        xr ^= a[i];
        if(m.find(xr^b) != m.end()){
            ans += m[xr^b];
        }
        m[xr]++;
    }
    return ans;
}

//TC: O(n);
//SC: O(n);