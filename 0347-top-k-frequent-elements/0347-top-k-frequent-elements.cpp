class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(const auto& val : nums) freq[val]++;
        vector<pair<int, int>> freq_arr;
        for(const auto& pair : freq) freq_arr.push_back({pair.second, pair.first});
        sort(freq_arr.begin(), freq_arr.end(), greater<pair<int, int>>());
        vector<int> result;
        for(int i = 0; i < k; i++) result.push_back(freq_arr[i].second);
        return result;
    }
};
