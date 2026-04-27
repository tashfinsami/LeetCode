class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        struct pair_hash {
            size_t operator()(const pair<char, int>& p) const {
                return hash<char>()(p.first) ^ (hash<int>()(p.second) << 1);
            }
        };
        struct nested_pair_hash {
            size_t operator()(const pair<char, pair<int,int>>& p) const {
                size_t h1 = hash<char>()(p.first);
                size_t h2 = hash<int>()(p.second.first);
                size_t h3 = hash<int>()(p.second.second);

        return h1 ^ (h2 << 1) ^ (h3 << 2);
            }
        };

        unordered_set<pair<char, int>, pair_hash> row_key;
        unordered_set<pair<char, int>, pair_hash> col_key;
        unordered_set<pair<char, pair<int,int>>, nested_pair_hash> blk_key;
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
