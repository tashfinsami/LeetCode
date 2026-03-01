class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left_vec(heights.size());
        stack<int> left_stk;

        for(int i = 0; i < heights.size(); i++) {
            if(left_stk.empty() || heights[i] > heights[left_stk.top()]){
                left_vec[i] = i;
                left_stk.push(i);
            }
            else if(heights[i] <= heights[left_stk.top()]) {
                while(!left_stk.empty() && heights[i] <= heights[left_stk.top()]) {
                    left_vec[i] = left_vec[left_stk.top()];
                    left_stk.pop();
                }
                left_stk.push(i);

            }
            //else if(heights[i] == heights[left_stk.top()]) left_vec[i] = left_vec[left_stk.top()];
        }

        vector<int> right_vec(heights.size());
        stack<int> right_stk;
        
        for(int i = heights.size() - 1; i >= 0; i--) {
            if(right_stk.empty() || heights[i] > heights[right_stk.top()]){
                right_vec[i] = i;
                right_stk.push(i);
            }
            else if(heights[i] <= heights[right_stk.top()]) {
                while(!right_stk.empty() && heights[i] <= heights[right_stk.top()]) {
                    right_vec[i] = right_vec[right_stk.top()];
                    right_stk.pop();
                }
                right_stk.push(i);

            }
            //else if(heights[i] == heights[right_stk.top()]) right_vec[i] = right_vec[right_stk.top()];
        }

        int area_max = 0;
        for(int i = 0; i < heights.size(); i++) {
            int area = heights[i] * (right_vec[i] - left_vec[i] + 1);
            area_max = max(area_max, area);
        }
        return area_max;
    }
};
