class Solution {
public:
    vector<int> makeFreq(string s, int l, int r) {
        vector<int> freq(26, 0);
        for(int i = l; i <= r; i++) freq[s[i] - 'a']++;
        return freq;
    }
    string makeKey(vector<int> freq) {
        string key = to_string(freq[0]);
        for(int i = 1; i < 26; i++) key += ',' + to_string(freq[i]);
        return key;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> f1 = makeFreq(s1, 0, s1.size() - 1);
        string k1 = makeKey(f1);
        int l = 0, r = s1.size() - 1;
        vector<int> f2 = makeFreq(s2, l, r);
        while(r < s2.size()) {
            string k2 = makeKey(f2);
            if(k2 == k1) return true;
            f2[s2[l] - 'a']--;
            if(r + 1 < s2.size()) f2[s2[r + 1] - 'a']++;
            l++;
            r++;
        }
        return false;
    }
};
