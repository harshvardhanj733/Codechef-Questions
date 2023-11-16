class Solution {
public:
    string findBin(int i, int n){
        string res = "";
        while(i != 0){
            if(i&1){
                res += '1';
            }
            else if(i&0){
                res += '0';
            }
            i = i >> 2;
        }
        while(res.size() != n){
            res += '0';
        }
        reverse(res.begin(), res.end());
        return res;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        for(int i = 0; i <= n; i++){
            string val = findBin(i, n);
            int j = 0;
            for(j = 0; j < n; j++){
                if(val == nums[j]){
                    break;
                }
            }
            if(j == n){
                return val;
            }
        }

        return "";
    }
};

//TC: O(n^2);
//SC: O(1);