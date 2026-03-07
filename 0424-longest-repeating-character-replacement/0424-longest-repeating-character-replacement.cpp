class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int max_freq = 0;
        int res = 0;
        int l = 0, r = 0;
        while(r < s.size()) {
            freq[s[r]]++;
            max_freq = max(max_freq, freq[s[r]]);
            if(r - l + 1 - max_freq - k == 1) {
                freq[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};
