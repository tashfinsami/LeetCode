class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_select = -1;
        int m = matrix.size();
        int l = 0, r = m;
        while(l < r) {
            int mid = l + (r - l) / 2;
            int last = matrix[mid].size() - 1;
            if(matrix[mid][last] >= target) {
                row_select = mid;
                r = mid;
            }
            else l = mid + 1;
        }
        if(row_select == -1) return false;
        int n = matrix[row_select].size();
        l = 0;
        r = n - 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(matrix[row_select][mid] < target) l = mid + 1;
            else if(matrix[row_select][mid] > target) r = mid - 1;
            else return true;
        }
        return false;

    }
};
