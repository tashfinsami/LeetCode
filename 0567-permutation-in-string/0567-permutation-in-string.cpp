class Solution {
public:
    string makeKey(string s, int l, int r) {
        vector<int> freq(26, 0);
        for(int i = l; i <= r; i++) freq[s[i] - 'a']++;
        string key = to_string(freq[0]);
        for(int i = 1; i < 26; i++) key += '+' + to_string(freq[i]);
        return key;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        string k1 = makeKey(s1, 0, s1.size() - 1);
        int l = 0, r = s1.size() - 1;
        while(r < s2.size()) {
            string k2 = makeKey(s2, l, r);
            if(k2 == k1) return true;
            l++;
            r++;
        }
        return false;
    }
};
