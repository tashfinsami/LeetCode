class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        int ans = nums[0];
        while(l < r) {
            int m = l + (r - l) / 2;
            if(m - 1 >= 0 && nums[m] < nums[m - 1]) ans = nums[m];
            else if(m + 1 < nums.size() && nums[m] > nums[m + 1]) ans = nums[m + 1];
            if(nums[m] >= nums[l]) l = m + 1;
            else r = m - 1;
        }
        return ans;
    }
};
