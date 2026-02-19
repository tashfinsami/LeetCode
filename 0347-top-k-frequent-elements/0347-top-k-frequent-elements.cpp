class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(const auto& val : nums) freq[val]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        for(const auto& pair : freq) {
            min_heap.push({pair.second, pair.first});
            if(min_heap.size() > k) min_heap.pop();
        }
        vector<int> result;
        while(!min_heap.empty()) {
            result.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return result;
    }
};
