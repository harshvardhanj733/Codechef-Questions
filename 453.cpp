class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0, check = nums[0];
        for(int i = 1; i<nums.size(); i++){
            count += nums[i] - check;
        }
        return count;
    }
};


// Time Complexity: O(nlogn)...can be easily optimised to O(n) by first running a loop and calculating minimum val instead of sorting

// Space Complexity: O(1);