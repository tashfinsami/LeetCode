class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < nums.size(); i++) {
            int l = i + 1, r = nums.size() - 1;
            if(nums[i] > 0 || nums[r] < 0) break;
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            while(l < r) {
                if(nums[i] + nums[l] + nums[r] < 0) l++;
                else if(nums[i] + nums[l] + nums[r] > 0) r--;
                else {
                    vector<int> temp;
                    temp.push_back(nums[i]); temp.push_back(nums[l]); temp.push_back(nums[r]);
                    if(res.empty() || res.back() != temp) res.push_back(temp);
                    l++;
                    r--;
                    while(l < r && nums[l] == nums[l - 1]) l++;
                }
            }
        }
        return res;
    }
};
