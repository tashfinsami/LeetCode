class TimeMap {
public:
    TimeMap() {
        
    }
    unordered_map<string, vector<pair<string, int>>> rec;
    
    void set(string key, string value, int timestamp) {
        rec[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        vector<pair<string, int>>& data = rec[key];
        int l = 0, r = data.size() - 1;
        int index = -1;
        while(l <= r) {
            int m = l + (r - l) / 2;
            if(data[m].second <= timestamp) {
                index = m;
                l = m + 1;
            }
            else r = m - 1;
        }
        return (index == -1) ? "" : data[index].first;
    }
};
