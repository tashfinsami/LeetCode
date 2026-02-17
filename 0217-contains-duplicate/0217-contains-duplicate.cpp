class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(int val : nums) seen.insert(val);
        if(seen.size() == nums.size()) return false;
        else return true;
    }
};