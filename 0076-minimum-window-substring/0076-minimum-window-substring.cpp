class Solution {
public:
    string minWindow(string s, string t) {
        if(!t.size() || !s.size() || t.size() > s.size()) return "";
        unordered_map<char, int> freq_t;
        for(char c : t) freq_t[c]++;
        unordered_map<char, int> freq_s;
        int matches = 0;
        pair<int, int> min_len = {-1, -1};
        int len = INT_MAX;
        int l = 0, r = 0;
        while(r < s.size()) {
            if(!freq_t[s[l]]) l++;
            r = max(r, l);
            freq_s[s[r]]++;
            if(freq_s[s[r]] <= freq_t[s[r]]) matches++;
            while(matches == t.size()) {
                if(r - l + 1 < len) {
                    len = r - l + 1;
                    min_len.first = l;
                    min_len.second = r;
                }
                freq_s[s[l]]--;
                if(freq_s[s[l]] < freq_t[s[l]]) matches--;
                l++;
            }
            r++;
        }
        string res;
        if(min_len.first != -1) for(int i = min_len.first; i <= min_len.second; i++) res += s[i];
        return res;
    }
};
