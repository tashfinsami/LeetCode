class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int m = l + (r - l) / 2;
            if(m - 1 >= 0 && nums[m] < nums[m - 1]) return nums[m];
            if(m + 1 < nums.size() && nums[m] > nums[m + 1]) return nums[m + 1];
            if(nums[m] >= nums[l]) l = m + 1;
            else r = m - 1;
        }
        return nums[0];
    }
};
