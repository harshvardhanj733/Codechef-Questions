class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res(nums.size());
        int i = 0, j = 1;
        for(int k = 0; k < nums.size(); k++){
            if(nums[k] >= 0){
                res[i] = nums[k];
                i += 2;
            }
            else{
                res[j] = nums[k];
                j += 2;
            }
        }
        return res;
    }
};

//TC: O(n);
//SC: O(n);