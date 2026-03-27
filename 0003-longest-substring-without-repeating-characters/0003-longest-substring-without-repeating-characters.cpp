class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count = 0;
        int l = 0, r = 0;
        unordered_map<char, int> index;
        while(r < s.size()) {
            if(index.contains(s[r])) {
                int new_l = index[s[r]] + 1;
                l = max(l, new_l);
            }
            index[s[r]] = r;
            count = max(count, r - l + 1);
            r++;
        }
        return count;
    }
};