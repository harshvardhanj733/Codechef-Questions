//Approach: Initialise a variable j = 0. Traverse the whole array linearly. If nums[i] is not zero, then swap nums[i] and nums[j] and increase the value of j by 1. Otherwise if nums[i] is 0, then do nothing. This way, all the zeroes will get swapped to the last positions.

//Time Complexity: O(n);
//Space Complexity: O(1); 

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]!=0){
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};