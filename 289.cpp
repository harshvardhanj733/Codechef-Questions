class Solution {
public:

    bool isSafe(int row, int col, int m, int n){
        if(row < 0 || row > m-1 || col < 0 || col > n-1){
            return false;
        }
        return true;
    }

    int count(vector<vector<int>> board, int i, int j){
        int ones = 0;
        for(int row = i-1; row <= i+1; row++){
            for(int col = j-1; col <= j+1; col++){
                if(isSafe(row, col, board.size(), board[0].size()) && !(row == i && col == j) && (board[row][col] == 1 || board[row][col] == 'a')){
                    ones++;
                }
            }
        }
        return ones;
    }

    void changeState(vector<vector<int>>& board, int i, int j){
        int ones = count(board, i, j);
        if(board[i][j] == 1 && (ones < 2 || ones > 3)){
            board[i][j] = 'a';
        }
        else if(board[i][j] == 0 && ones == 3){
            board[i][j] = 'b';
        }
    }

    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                changeState(board, i, j);
            }
        }

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(board[i][j] == 'a'){
                    board[i][j] = 0;
                }
                else if(board[i][j] == 'b'){
                    board[i][j] = 1;
                }
            }
        }
    }
};

//Time Complexity: O(9*n);
//Space Complexity: O(1);