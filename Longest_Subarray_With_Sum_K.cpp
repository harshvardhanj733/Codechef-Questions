int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int i = 0, j = 0;
    int maxLen = 0;
    long long sum = 0;
    while(i < a.size()){
        sum += a[i];
        if(sum == k){
            maxLen = max(maxLen, i - j + 1);
        }
        else if(sum > k){
            while(j <= i && sum > k){
                sum -= a[j];
                j++;
            }
            if(sum == k){
                maxLen = max(maxLen, i - j + 1);
            }
        }

        i++;
    }

    return maxLen;
}

//TC: O(n);
//SC: O(1);