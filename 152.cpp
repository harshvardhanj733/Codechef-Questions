class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(res < nums[i]){
                res = nums[i];
            }
        }

        int currMax = 1, currMin = 1;
        for(int i = 0; i < nums.size(); i++){
            int temp = nums[i]*currMax;
            currMax = max(nums[i]*currMax, max(nums[i]*currMin, nums[i]));
            currMin = min(temp, min(nums[i]*currMin, nums[i]));

            res = max(res, currMax);
        }

        return res;
    }
};

//TC: O(n);
//SC: O(1);