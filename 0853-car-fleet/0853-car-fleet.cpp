class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> rec(position.size());
        for(int i = 0; i < position.size(); i++) {
            rec[i].first = position[i];
            rec[i].second = speed[i];
        }
        sort(rec.rbegin(), rec.rend());
        vector<double> buffer;
        for(int i = 0; i < position.size(); i++) {
            double time = (target - rec[i].first) / (double)rec[i].second; 
            if(buffer.size() && time <= buffer.back()) continue;
            else buffer.push_back(time); 
        }
        return buffer.size();
    }
};
