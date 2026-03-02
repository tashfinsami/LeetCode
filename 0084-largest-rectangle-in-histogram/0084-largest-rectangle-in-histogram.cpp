class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left_vec(n, -1);
        vector<int> right_vec(n, n);
        stack<int> stk;
        for(int i = 0; i < n; i++) {
            if(!stk.empty() && heights[i] <= heights[stk.top()]) {
                while(!stk.empty() && heights[i] <= heights[stk.top()]) {
                    stk.pop();
                }
            }
            if(!stk.empty()) left_vec[i] = stk.top();
            stk.push(i);
        }
        while(!stk.empty()) stk.pop();
        for(int i = n - 1; i >= 0; i--) {
            if(!stk.empty() && heights[i] <= heights[stk.top()]) {
                while(!stk.empty() && heights[i] <= heights[stk.top()]) {
                    stk.pop();
                }
            }
            if(!stk.empty()) right_vec[i] = stk.top();
            stk.push(i);
        }
        int area_max = 0;
        for(int i = 0; i < n; i++) {
            left_vec[i]++;
            right_vec[i]--;
            int area = heights[i] * (right_vec[i] - left_vec[i] + 1);
            area_max = max(area_max, area);
        }
        return area_max;
    }
};
