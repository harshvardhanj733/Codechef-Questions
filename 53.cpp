class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0], maxi = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(sum < 0){
                sum = 0;
            }
            sum += nums[i];
            maxi = max(maxi, sum);
        }

        return maxi;

    }
};
//TC: O(n);
//SC: O(1);