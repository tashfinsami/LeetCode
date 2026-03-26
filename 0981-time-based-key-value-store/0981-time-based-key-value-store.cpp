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
        if(!data.size() || timestamp < data[0].second) return "";
        int l = 0, r = data.size() - 1;
        int index;
        while(l <= r) {
            int m = l + (r - l) / 2;
            index = m;
            if(data[m].second == timestamp) break;
            else if(data[m].second < timestamp) l = m + 1;
            else r = m - 1;
        }
        return (data[index].second <= timestamp) ? data[index].first : data[index - 1].first;
    }
};


/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */