class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = i+1, check = false;
        while(j < nums.size()){
            if(nums[i] == nums[j] && check == false){
                check = true;
                nums[i+1] = nums[j];
                i++; j++;
            }
            else if(nums[i] == nums[j] && check == true){
                j++;
            }
            else{
                check = false;
                nums[i+1] = nums[j];
                i++; j++;
            }
        }

        return i+1;
    }
};

//TC: O(n);
//SC: O(1);