//Approach: Traverse the whole array linearly. If any element is 0, set the row and column of that element to 'a' except those that are already 0. Then traverse again and set the ones that are 'a' to 0.

//Time Complexity: O(n^3)
//Space Complexity: O(1)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(matrix[i][j] == 0){
                    for(int k = 0; k<m; k++){
                        if(k!=i && matrix[k][j] != 0){
                            matrix[k][j] = 'a';
                        }
                    }
                    for(int k = 0; k<n; k++){
                        if(k!=j && matrix[i][k] != 0){
                            matrix[i][k] = 'a';
                        }
                    }
                }
            }
        }

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(matrix[i][j] == 'a'){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

