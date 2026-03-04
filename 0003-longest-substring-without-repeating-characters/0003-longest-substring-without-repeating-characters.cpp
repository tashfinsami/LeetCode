class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count = 0;
        int l = 0, r = 0;
        unordered_set<char> char_set;
        while(r < s.size()) {
            //if(char_set.find(s[r]) != char_set.end()) {
                while(char_set.find(s[r]) != char_set.end()) {
                    char_set.erase(s[l]);
                    l++;
                }
            //}
            char_set.insert(s[r]);
            count = max(count, r - l + 1);
            r++;
        }
        return count;
    }
};
