class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        int idx[3][9][9] = {{0, 0, 0}};
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                if(board[row][col] == '.') continue;
                int num = board[row][col] - '0' - 1;
                if(idx[0][row][num]) return false;
                if(idx[1][col][num]) return false;
                if(idx[2][(row / 3) * 3 + (col / 3)][num]) return false;

                idx[0][row][num] = 1;
                idx[1][col][num] = 1;
                idx[2][(row / 3) * 3 + (col / 3)][num] = 1;
            }
        }
        return true;
    }
};
