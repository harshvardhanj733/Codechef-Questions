class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 1){
            return;
        }

        int n = nums.size();
        int i = n-1;
        for(i = n - 1; i >= 1; i--){
            if(nums[i] > nums[i-1]){
                int j = n-1;
                while(j >= i && nums[j] <= nums[i-1]){
                    j--;
                }
                swap(nums[i-1], nums[j]);
                break;
            }
        }
        reverse(nums.begin() + i, nums.end());
    }
};

//TC: O(n);
//SC: O(1);