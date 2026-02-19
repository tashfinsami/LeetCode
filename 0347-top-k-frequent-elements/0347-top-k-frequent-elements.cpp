class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(const auto& val : nums) freq[val]++;
        unordered_map<int, vector<int>> list_freq;
        for(const auto& pair : freq) list_freq[pair.second].push_back(pair.first);
        vector<int> result;
        for(int i = nums.size(); i > 0; i--) {
            for(int val : list_freq[i]) {
                result.push_back(val);
                if(result.size() == k) return result;
            }
        }
        return result;
    }
};
