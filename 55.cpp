class Solution {
public:
    bool canJump(vector<int>& nums) {
        // if(nums.size() == 1){
        //     return true;
        // }
        // for(int i = nums.size()-2; i>=0; i--){
        //     if(nums[i] == 0){
        //         bool check = false;
        //         for(int j = i-1; j>=0; j--){
        //             if(nums[j] > i-j){
        //                 check = true;
        //                 break;
        //             }
        //         }
        //         if(check == false){
        //             return false;
        //         }
        //     }
        // }
        // return true;

        //Time Complexity: O(n^2);
        //Space Complexity: O(1);

        int reach = 0;
        for(int i = 0; i<nums.size(); i++){
            if(i > reach){
                return false;
            }
            reach = max(reach, i+nums[i]);
        }
        return true;

        //Time Complexity: O(n);
        //Space Complexity: O(1);
    }
};