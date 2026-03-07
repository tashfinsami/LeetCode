class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_set<char> char_set(s.begin(), s.end());
        int res = 0;
        for(char c : char_set) {
            int count = 0;
            int l = 0, r = 0;
            while(r < s.size()) {
                if(s[r] == c) count++;
                if(r - l + 1 > count + k) {
                    if(s[l] == c) count--;
                    l++;
                }
                res = max(res, r - l + 1);
                r++;
            }
        }
        return res;
    }
};
