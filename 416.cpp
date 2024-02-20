class Solution {
private:
    bool solve(vector<int>& nums, int sum, int i, vector<vector<int>>& dp){
        if(sum == 0){
            return true;
        }
        if(i == nums.size()){
            return false;
        }
        if(dp[sum][i] != -1){
            if(dp[sum][i] == 1){
                return true;
            }
            return false;
        }

        bool ans = false;
        if(ans == false && sum - nums[i] >= 0){
            ans |= solve(nums, sum - nums[i], i+1, dp);
        }
        if(ans == false){
            ans |= solve(nums, sum, i+1, dp);
        }

        if(ans == false){
            dp[sum][i] = 0;
        }
        else{
            dp[sum][i] = 1;
        }

        return ans;
    }

    bool solveTab(vector<int>& nums, int sum){
        int n = nums.size();
        vector<vector<bool>> dp(sum + 1, vector<bool> (n + 1, false));
        for(int i = 0; i <= n; i++){
            dp[0][i] = true;
        }

        for(int i = 1; i <= sum; i++){
            for(int j = n-1; j >= 0; j--){
                bool ans = false;
                if(ans == false && i - nums[j] >= 0){
                    ans |= dp[i - nums[j]][j+1];
                }
                if(ans == false){
                    ans |= dp[i][j+1];
                }

                dp[i][j] = ans;
                if(ans == true && i == sum){
                    return true;
                }
            }
        }
        return false;

        // for(int i = 0; i <= n; i++){
        //     if(dp[sum][i] == true){
        //         return true;
        //     }
        // }
        // return false;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        if(sum & 1){
            return false;
        }

        // vector<vector<int>> dp(sum/2+1, vector<int> (nums.size(), -1));
        // return solve(nums, sum/2, 0, dp);
        return solveTab(nums, sum/2);
    }
};

//TC: O(n^sum/2);
//SC: O(n^sum/2);