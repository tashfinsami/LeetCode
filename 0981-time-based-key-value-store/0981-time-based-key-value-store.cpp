class TimeMap {
public:
    TimeMap() {
        
    }
    unordered_map<string, vector<pair<string, int>>> rec;
    
    void set(string key, string value, int timestamp) {
        rec[key].emplace_back(value, timestamp);
    }
    
    string get(string key, int timestamp) {
        vector<pair<string, int>>& data = rec[key];
        int l = 0, r = data.size() - 1;
        string res = "";
        while(l <= r) {
            int m = l + (r - l) / 2;
            if(data[m].second <= timestamp) {
                res = data[m].first;
                l = m + 1;
            }
            else r = m - 1;
        }
        return res;
    }
};
