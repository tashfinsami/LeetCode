class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> alnum_arr;
        for(char ch : s) {
            if(isalnum(ch)) alnum_arr.push_back(tolower(ch));
        }
        int n = alnum_arr.size();
        if(n == 1) return true;
        for(int i = 0, j = n - 1; i < j; i++, j--) {
            if(alnum_arr[i] != alnum_arr[j]) return false;
        }
        return true;
    }
};
