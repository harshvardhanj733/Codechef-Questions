#define M 1000000007
class Solution {
private:
    bool inLimits(int m, int n, int i, int j){
        return i < m && j < n && i >= 0 && j >= 0;
    }
    int solve(int m, int n, int moves, int i, int j, vector<vector<vector<int>>>& dp){
        if(!inLimits(m, n, i, j)){
            return 1;
        }
        if(moves == 0){
            return 0;
        }

        if(dp[i][j][moves] != -1){
            return dp[i][j][moves];
        }

        int ans = 0;
        ans = (ans + solve(m, n, moves-1, i+1, j, dp)%M)%M;
        ans = (ans + solve(m, n, moves-1, i-1, j, dp)%M)%M;
        ans = (ans + solve(m, n, moves-1, i, j+1, dp)%M)%M;
        ans = (ans + solve(m, n, moves-1, i, j-1, dp)%M)%M;

        return dp[i][j][moves] = ans;
    }
    
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int> (maxMove + 1, -1)));
        return solve(m, n, maxMove, startRow, startColumn, dp);
    }
};

//TC: O(n^3);
//SC: O(n^3);