class Solution {

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> index;

        for(const auto& inp_str : strs) {
            vector<int> freq(26, 0);
            for(char let : inp_str) freq[let - 'a']++;
            string key = to_string(freq[0]);
            for(int i = 1; i < 26; i++) key += ',' + to_string(freq[i]);
            index[key].push_back(inp_str);
        }

        vector<vector<string>> result;

        for(const auto& idx_pair : index) result.push_back(idx_pair.second);

        return result;
    }
};
