class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> f1(26, 0);
        vector<int> f2(26, 0);
        for(int i = 0; i < s1.size(); i++) {
            f1[s1[i] - 'a']++;
            f2[s2[i] - 'a']++;
        }
        int matches = 0;
        for(int i = 0; i < 26; i++) {
            if(f1[i] == f2[i]) matches++;
        } 
        int l = 0, r = s1.size() - 1;
        while(r < s2.size()) {
            if(matches == 26) return true;

            if(r + 1 < s2.size()) {
                f2[s2[r + 1] - 'a']++;
                if(f2[s2[r + 1] - 'a'] == f1[s2[r + 1] - 'a']) matches++;
                else if(f2[s2[r + 1] - 'a'] == f1[s2[r + 1] - 'a'] + 1) matches--;

            f2[s2[l] - 'a']--;
            if(f2[s2[l] - 'a'] == f1[s2[l] - 'a']) matches++;
            else if(f2[s2[l] - 'a'] == f1[s2[l] - 'a'] - 1) matches--;
            }

            l++;
            r++;
        }
        return false;
    }
};
