int maximumFrequency(vector<int> &arr, int n)
{
    //Write your code here
    unordered_map<int, int> m;
    int maxFreq = 0;
    for(int i = 0; i < n; i++){
        m[arr[i]]++;
        maxFreq = max(maxFreq, m[arr[i]]);
    }

    for(int i = 0; i < n; i++){
        if(m[arr[i]] == maxFreq){
            return arr[i];
        }
    }

    return -1;
}

//TC: O(n);
//SC: O(n);