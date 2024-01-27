class Solution {
private:
    int binSearch(vector<int>& nums, int i, int j){
        if(i > j){
            return -1;
        }
        if(i == j){
            return nums[i];
        }

        int mid = i + (j-i)/2;
        int l = mid-1;
        int r = mid+1;
        if((l >= i && nums[mid] != nums[l]) && (r <= j && nums[mid] != nums[r])){
            return nums[mid];
        }

        int ans1 = 0, ans2 = 0;
        if(l >= i && nums[mid] == nums[l]){
            ans1 = binSearch(nums, i, l-1);
        }
        else{
            ans1 = binSearch(nums, i, l);
        }
        if(r <= j && nums[mid] == nums[r]){
            ans2 = binSearch(nums, r+1, j);
        }
        else{
            ans2 = binSearch(nums, r, j);
        }

        return (ans1 == -1)?ans2:ans1;
        
    }
public:
    int singleNonDuplicate(vector<int>& nums) {
        // return binSearch(nums, 0, nums.size() - 1);
        if(nums.size() == 1){
            return nums[0];
        }
        if(nums[0] != nums[1]){
            return nums[0];
        }
        if(nums[nums.size() - 1] != nums[nums.size() - 2]){
            return nums[nums.size() - 1];
        }
        int l = 1, r = nums.size() - 2;
        while(l <= r){
            int mid = l + (r - l)/2;
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
                return nums[mid];
            }
            else if(nums[mid] == nums[mid-1]){
                if(mid&1){
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }
            else{
                if(mid&1){
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
        }

        return -1;
    }
};

//TC: O(logn);
//SC: O(1);