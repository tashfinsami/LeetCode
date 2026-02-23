class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int l_max = height[l], r_max = height[r];
        int count = 0;
        while(l < r) {
            if(height[l] < l_max) count += l_max - height[l];
            if(height[r] < r_max) count += r_max - height[r];
            if(l_max <= r_max) {
                l++;
                l_max = max(l_max, height[l]);
            }
            else {
                r--;
                r_max = max(r_max, height[r]);
            }
        }
        return count;
    }
};
