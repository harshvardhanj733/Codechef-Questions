class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 3; i++){
            if(i != 0 && nums[i] == nums[i-1]){
                continue;
            }
            for(int j = i + 1; j < n - 2; j++){
                if(j != i+1 && nums[j] == nums[j-1]){
                    continue;
                }
                int k = j + 1, l = n-1;
                while(k < l){
                    long long ans = nums[i] + nums[j];
                    ans += nums[k];
                    ans += nums[l];

                    if(ans == target){
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        res.push_back(temp);
                        k++;
                        l--;
                        while(k < l && nums[k] == nums[k-1]){
                            k++;
                        }
                        while(k < l && nums[l] == nums[l+1]){
                            l--;
                        }
                    }
                    else if(ans < target){
                        k++;
                        while(k < l && nums[k] == nums[k-1]){
                            k++;
                        }
                    }
                    else{
                        l--;
                        while(k < l && nums[l] == nums[l+1]){
                            l--;
                        }
                    }
                }
            }
        }

        return res;
    }
};

//NOTE: Interviewer is looking for an answer without using Set or Hashmap in O(n^3) O(1) time!!

//TC: O(n^3);
//SC: O(1);
