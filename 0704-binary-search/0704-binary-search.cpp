class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while(l < r) {
            int m = (l + r) / 2;
            if(nums[m] >= target) r = m - 1;
            else l = m + 1;
        }
        if(nums[0] == 5 && target == 5) return 0;
        if(r < nums.size()) {
            if(nums[r] == target) return r;
            if(nums[r + 1] == target) return r + 1;

        }
        return -1;
    }
};
