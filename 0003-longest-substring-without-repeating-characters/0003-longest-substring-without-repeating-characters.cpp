class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count = 0;
        int l = 0, r = 1;
        while(r < s.size()) {
            for(int i = l; i < r; i++) {
                if(s[i] == s[r]) {
                    count = max(count, r - 1 - l + 1);
                    l = i + 1;
                    break;
                }
            }
            r++;
        }
        if(s.size()) count = max(count, r - 1 - l + 1);
        return count;
    }
};
