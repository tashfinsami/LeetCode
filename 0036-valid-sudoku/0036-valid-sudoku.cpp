class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        unordered_map<int, unordered_set<char>> row_idx;
        unordered_map<int, unordered_set<char>> col_idx;
        map<pair<int, int>, unordered_set<int>> blk_idx;

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                char ch = board[row][col];
                if(ch == '.') continue;
                
                pair<int, int> blk = {row / 3, col / 3};

                if(row_idx[row].count(ch)) return false;
                if(col_idx[col].count(ch)) return false;
                if(blk_idx[blk].count(ch)) return false;

                row_idx[row].insert(ch);
                col_idx[col].insert(ch);
                blk_idx[blk].insert(ch);
            }
        }
        return true;
    }
};
