int longestSuccessiveElements(vector<int>&a) {
    // Write your code here.
    unordered_set<int> s;
    for(int i = 0; i < a.size(); i++){
        s.insert(a[i]);
    }

    int maxLen = 1;
    for(auto i: s){
        if(s.find(i - 1) == s.end()){
            int j = i+1;
            int count = 1;
            while(s.find(j) != s.end()){
                count++;
                j++;
            }
            maxLen = max(maxLen, count);
        }
    }

    return maxLen;
}

//TC: O(n);
//SC: O(n);