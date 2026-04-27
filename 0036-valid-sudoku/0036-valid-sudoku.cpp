class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        set<pair<char, int>> row_key;
        set<pair<char, int>> col_key;
        set<pair<char, pair<int, int>>> blk_key;
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                char ch = board[row][col];
                if(ch == '.') continue;
                if(row_key.find({ch, row}) != row_key.end()) return false;
                if(col_key.find({ch, col}) != col_key.end()) return false;
                if(blk_key.find({ch, {row / 3, col / 3}}) != blk_key.end()) return false;

                row_key.insert({ch, row});
                col_key.insert({ch, col});
                blk_key.insert({ch, {row / 3, col / 3}});
            }
        }
        return true;
    }
};
