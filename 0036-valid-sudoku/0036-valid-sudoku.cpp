class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row_idx[9] = {0};
        int col_idx[9] = {0};
        int blk_idx[9] = {0};
        for(int row = 0; row < 9; row++) {
            for(int col = 0; col < 9; col++) {
                if(board[row][col] == '.') continue;
                int num = board[row][col] - '0' - 1;
                int blk = (row / 3) * 3 + (col / 3);

                if(row_idx[row] & (1 << num)) return false;
                if(col_idx[col] & (1 << num)) return false;
                if(blk_idx[blk] & (1 << num)) return false;

                row_idx[row] = row_idx[row] | (1 << num);
                col_idx[col] = col_idx[col] | (1 << num);
                blk_idx[blk] = blk_idx[blk] | (1 << num);
            }
        }
        return true;
    }
};
