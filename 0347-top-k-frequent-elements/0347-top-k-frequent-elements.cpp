class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(const auto& val : nums) freq[val]++;
        map<int, vector<int>, greater<int>> top_freqs;
        for(const auto& pair : freq) top_freqs[pair.second].push_back(pair.first);
        vector<int> result;
        int count = k;
        for(const auto& pair : top_freqs) {
            if(count) {
                result.insert(result.end(), pair.second.begin(), pair.second.end());
                count -= pair.second.size();
            }
            else break;
        }
        int extra = result.size() - k;
        while(extra--) result.pop_back();
        return result;
    }
};
