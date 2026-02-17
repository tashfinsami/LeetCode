class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> match;
        for(char p : s) match[p]++;
        for(char q : t) {
            if(match[q]) match[q]--;
            else return false;
        }
        return true;
    }
};