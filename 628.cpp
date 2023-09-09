class Solution {
public:

    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = nums.size()-1;
        if(i == 2){
            return nums[i]*nums[i-1]*nums[i-2];
        }
        else if(nums[nums.size()-1] <= 0 || nums[0] >= 0){
            return nums[i]*nums[i-1]*nums[i-2];
        } 
        else{
            vector<int> temp;
            temp.push_back(nums[0]);
            temp.push_back(nums[i-1]);
            if(i-2!=1){
                temp.push_back(nums[1]);
                temp.push_back(nums[i-2]);
            }
            else{
                temp.push_back(nums[1]);
            }
            int mul = -1;
            for(int i = 0; i<temp.size()-1; i++){
                for(int j = i+1; j<temp.size(); j++){
                    mul = max(mul, temp[i]*temp[j]);
                }
            }
            return nums[i]*mul;
        }
    }
};