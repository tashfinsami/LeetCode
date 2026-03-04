class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count = 0;
        int start = 0, end = 1;
        while(end < s.size()) {
            for(int j = start; j < end; j++) {
                if(s[j] == s[end]) {
                    count = max(count, end - 1 - start + 1);
                    start++;
                    end = start;
                    break;
                }
            }
            end++;
        }
        if(s.size()) count = max(count, end - 1 - start + 1);
        return count;
    }
};
