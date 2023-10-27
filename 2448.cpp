class Solution {
public:

    static bool cmp(vector<int> num1, vector<int> num2){
        if(num1[0] != num2[0]){
            return num1[0] < num2[0];
        }

        return num1[1] < num2[1];
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<vector<int>> combinedNums;
        for(int i = 0; i < nums.size(); i++){
            vector<int> temp;
            temp.push_back(nums[i]);
            temp.push_back(cost[i]);
            combinedNums.push_back(temp);
        }

        sort(combinedNums.begin(), combinedNums.end(), cmp);

        vector<long long int> prefVal;
        vector<long long int> suffVal(combinedNums.size(), 0);
        long long int prefSum = 0;
        long long int suffSum = 0;

        for(int i = 0; i < combinedNums.size(); i++){
            if(i == 0){
                prefSum += combinedNums[i][1];
                prefVal.push_back(0);

                suffSum += combinedNums[combinedNums.size()-1 - i][1];
            }
            else{
                long long int diff1 = combinedNums[i][0] - combinedNums[i-1][0];
                long long int sum1 = prefVal[i-1] + prefSum*diff1;
                prefSum += combinedNums[i][1];
                prefVal.push_back(sum1);

                long long int diff2 = combinedNums[combinedNums.size() - i][0] - combinedNums[combinedNums.size() - 1 - i][0];
                long long int sum2 = suffVal[combinedNums.size() - i] + suffSum*diff2;
                suffSum += combinedNums[combinedNums.size() - 1 - i][1];
                suffVal[combinedNums.size() - 1 - i] = sum2;
            }
        }

        long long int mini = prefVal[0] + suffVal[0];
        for(int i = 1; i < prefVal.size(); i++){
            if(prefVal[i] + suffVal[i] < mini){
                mini = prefVal[i] + suffVal[i];
            }
        }

        return mini;
    }
};

//TC: O(nlogn);
//SC: O(n);