class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int, int> remMap;
        int sum = 0, count = 0;

        remMap[0] = 1;

        for(int i = 0; i<nums.size(); i++){
            sum += nums[i];
            int rem = sum%k;

            if(rem < 0){
                rem = (rem + k)%k;
            }

            count += remMap[rem];

            remMap[rem]++;
        }

        return count;
    }
};