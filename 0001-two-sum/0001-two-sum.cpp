class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if(index.contains(complement)) {
                result.push_back(index[complement]);
                result.push_back(i);
                break;
            }
            else index[nums[i]] = i;
        }
        return result;
    }
};