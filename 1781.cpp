class Solution {
public:

    int solve(unordered_map<char, int>& m){
        int maxi = 0;
        int mini = INT_MAX;
        for(auto i: m){
            maxi = max(maxi, i.second);
            mini = min(mini, i.second);
        }

        return maxi - mini;
    }

    int beautySum(string s) {
        int sum = 0;
        for(int i = 0; i < s.size() - 1; i++){
            unordered_map<char, int> m;
            m[s[i]]++;
            for(int j = i + 1; j < s.size(); j++){
                m[s[j]]++;
                sum += solve(m);
            }
        }

        return sum;

        //TC: O(N^2);
        //SC: O(26)
    }
};