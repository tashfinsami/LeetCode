class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> rec(position.size());
        for(int i = 0; i < position.size(); i++) {
            rec[i].first = position[i];
            rec[i].second = speed[i];
        }
        sort(rec.rbegin(), rec.rend());
        int count = 1;
        double time_prev = (target - rec[0].first) / (double)rec[0].second;
        for(int i = 1; i < position.size(); i++) {
            double time_cur = (target - rec[i].first) / (double)rec[i].second;
            bool flag = false;
            if(time_cur <= time_prev) continue;
            else {
                count++;
                time_prev = time_cur;
            }
        }
        return count;
    }
};