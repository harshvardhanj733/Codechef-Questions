class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> res;
        for(int i = 0; i<nums.size(); i++){
            res.insert(nums[i]);
        }
        nums.clear();
        set<int>::iterator i;
        for(i = res.begin(); i!=res.end(); i++){
            nums.push_back(*i);
        }
        return res.size();
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)

// Approach: Used sets to store non-duplicate values, then inserted those values in the original vector.