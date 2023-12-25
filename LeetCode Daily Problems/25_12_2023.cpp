//Approach: We are building various strings using a for loop and checking if they satisfy the condition. If they do, we're recursively calling for the next index and doing the same process again. Since the recursive solution is giving TLE, we are using memoization to reduce the time complexity as there can be same subproblems multiple times.

class Solution {
private:
    int solve(string s, int i, vector<int>& dp){
        if(i >= s.size()){
            return 1;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int count = 0;
        string temp = "";
        int num = 0;
        for(int j = i; j < s.size() && num < INT_MAX/10; j++){
            temp.push_back(s[j]);
            num = stoi(temp);
            if(num >= 1 && num <= 26 && temp[0] != '0'){
                count += solve(s, j+1, dp);
            }
        }

        return dp[i] = count;
    }
public:
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1, -1);
        return solve(s, 0, dp);
    }
};

//TC: O(n);
//SC: O(n);