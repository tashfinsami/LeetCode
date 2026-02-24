class Solution {
public:
    bool isValid(string s) {
        stack<char> buffer;
        unordered_map<char, char> mapper = {{')', '('}, {'}', '{'}, {']', '['}};
        for(char ch : s) {
            if(!buffer.empty() && mapper.contains(ch) && mapper[ch] == buffer.top()) buffer.pop();
            else buffer.push(ch);
        }
        if(!buffer.empty()) return false;
        else return true;
    }
};
