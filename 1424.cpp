class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        // int maxCol = 0;
        // for(int i = 0; i < nums.size(); i++){
        //     maxCol < nums[i].size() ? maxCol = nums[i].size() : maxCol = maxCol;
        // }

        // vector<int> res;
        // for(int i = 0; i < nums.size(); i++){
        //     int row = i, col = 0;
        //     while(row >= 0 && col < maxCol){
        //         if(nums[row].size() > col){
        //             res.push_back(nums[row][col]);
        //         }
        //         row--; col++;
        //     }
        // }

        // for(int i = 1; i < maxCol; i++){
        //     int row = nums.size() - 1, col = i;
        //     while(row >= 0 && col < maxCol){
        //         if(nums[row].size() > col){
        //             res.push_back(nums[row][col]);
        //         }
        //         row--; col++;
        //     }
        // }

        // return res;
        map<int, vector<int>> m;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < nums[i].size(); j++){
                m[i+j].push_back(nums[i][j]);
            }
        }
        vector<int> res;
        for(auto i: m){
            for(int j = i.second.size() - 1; j >= 0; j--){
                res.push_back(i.second[j]);
            }
        }

        return res;
    }
};

//TC: O(n*m);
//SC: O(n*m);