class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq_t;
        for(char c : t) freq_t[c]++;
        unordered_map<char, int> freq_s;
        int matches = 0;
        vector<int> min_len(2, -1);
        int l = 0, r = 0;
        while(r < s.size()) {
            if(!freq_t[s[l]]) {
                while(!freq_t[s[l]] && l < s.size()) l++;
                if(l >= s.size()) break;
                r = max(r, l);
            }
            freq_s[s[r]]++;
            if(freq_s[s[r]] <= freq_t[s[r]]) matches++;
            if(matches == t.size()) {
                if(min_len[0] == -1 || r - l < min_len[1] - min_len[0]) {
                    min_len[0] = l;
                    min_len[1] = r;
                }
                freq_s[s[l]]--;
                if(freq_s[s[l]] < freq_t[s[l]]) matches--;
                int temp = l;
                l++;

                freq_s[s[r]]--;
                if(freq_s[s[r]] < freq_t[s[r]]) matches--;
                r--;
            }
            r++;
        }
        string res;
        if(min_len[0] != -1) for(int i = min_len[0]; i <= min_len[1]; i++) res += s[i];
        return res;
    }
};
