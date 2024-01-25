class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // unordered_map<int, int> m;
        // for(int i = 0; i < nums.size(); i++){
        //     m[nums[i]]++;
        // }
        // vector<int> res;
        // for(auto i: m){
        //     if(i.second > nums.size()/3){
        //         res.push_back(i.first);
        //     }
        // }
        // return res;

        int cnt1 = 1, cnt2 = 0, el1 = nums[0], el2 = 0;
        for(int i = 1; i < nums.size(); i++){
            if(cnt1 == 0 && nums[i] != el2){
                cnt1++; el1 = nums[i];
            }
            else if(cnt2 == 0 && nums[i] != el1){
                cnt2++; el2 = nums[i];
            }
            else if(nums[i] == el1){
                cnt1++;
            }
            else if(nums[i] == el2){
                cnt2++;
            }
            else{
                cnt1--; cnt2--;
            }
        }

        vector<int> res;

        //check if both are > n/3;
        int limit = nums.size()/3 + 1;
        int count1 = 0, count2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == el1){
                count1++;
            }
            else if(nums[i] == el2){
                count2++;
            }

            if(count1 >= limit && count2 >= limit){
                break;
            }
        }

        if(count1 >= limit){
            res.push_back(el1);
        }
        if(count2 >= limit){
            res.push_back(el2);
        }

        return res;
    }
};

//TC: O(n);
//SC: O(1);