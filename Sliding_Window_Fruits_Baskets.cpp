int findMaxFruits(vector<int> &arr, int n) {
    // Write your code here.
    map<int, int> m;
    set<int> s;
    int i = 0, ans = 0;
    for(int j = 0; j < n; j++){
        m[arr[j]]++;
        s.insert(arr[j]);

        while(s.size() > 2){
            m[arr[i]]--;
            if(m[arr[i]] == 0){
                s.erase(arr[i]);
            }
            i++;
        }

        ans = max(ans, j - i + 1);
    }

    return ans;
}

//TC: O(n);
//SC: O(n);