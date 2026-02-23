class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int w = heights.size() - 1;
        int max_area = 0;
        while(l < r) {
            int area = min(heights[r], heights[l]) * w--;
            max_area = max(max_area, area);
            if(heights[r] >= heights[l]) l++;
            else r--;
        }
        return max_area;
    }
};
