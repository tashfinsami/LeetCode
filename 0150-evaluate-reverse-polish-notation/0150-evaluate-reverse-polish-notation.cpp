class Solution {
public:
    int calc(string str, int n1, int n2) {
        int res;
        if(str == "+") res = n1 + n2;
        else if(str == "-") res = n1 - n2;
        else if(str == "*") res =  n1 * n2;
        else if(str == "/") res =  n1 / n2;
        return res;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> buffer;
        for(string str : tokens) {
            if(str == "+" || str == "-" || str == "*" || str == "/") {
                int n2 = buffer.top();
                buffer.pop();
                int n1 = buffer.top();
                buffer.pop();
                int n3 = calc(str, n1, n2);
                buffer.push(n3);
            }
            else {
                buffer.push(stoi(str));
            }
        }
        int res = buffer.top();
        return res;
    }
};
