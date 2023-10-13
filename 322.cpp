class Solution {
private:
    int solveTab(vector<int> coins, int amount){
        int n = coins.size();
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;

        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < n; j++){
                if(i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX){
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        return dp[amount]!=INT_MAX?dp[amount]:-1;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        return solveTab(coins, amount);
    }
};

//TC: O(n)
//SC: O(n)