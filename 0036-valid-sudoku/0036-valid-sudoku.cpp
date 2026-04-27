class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        unordered_set<int> row_idx;
        unordered_set<int> col_idx;
        unordered_set<int> blk_idx;
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                if(board[row][col] == '.') continue;
                int num = board[row][col] - '0';
                
                int row_key = row * 10 + num;
                int col_key = col * 10 + num;
                int blk_key = (row / 3) * 100 + (col / 3) * 10 + num;
                
                if(row_idx.count(row_key)) return false;
                if(col_idx.count(col_key)) return false;
                if(blk_idx.count(blk_key)) return false;

                row_idx.insert(row_key);
                col_idx.insert(col_key);
                blk_idx.insert(blk_key);
            }
        }
        return true;
    }
};
