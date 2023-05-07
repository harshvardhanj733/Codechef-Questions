class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> red, white, blue;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 0){
                red.push_back(nums[i]);
            }
            else if(nums[i] == 1){
                white.push_back(nums[i]);
            }
            else{
                blue.push_back(nums[i]);
            }
        }
        nums.clear();
        nums.insert(nums.begin(), red.begin(), red.end());
        nums.insert(nums.end(), white.begin(), white.end());
        nums.insert(nums.end(), blue.begin(), blue.end());
        
    }
};



// Time Complexity : O(n)
// Space Complexity : O(n)

// Approach: Sort the numbers by quickly inserting them in 3 separate vectors, then copy those 3 vectors in the original vector.