class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> en_buff;
        vector<int> res(temperatures.size(), 0);
        for(int i = 0; i < temperatures.size(); i++) {
            while(!en_buff.empty() && temperatures[i] > en_buff.top().first) {
                int prev_day = en_buff.top().second;
                int days = i - prev_day;
                res[prev_day] = days;
                en_buff.pop();
            }
            en_buff.push({temperatures[i], i});
        }
        return res;
    }
};
