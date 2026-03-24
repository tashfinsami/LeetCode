class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_num = -1;
        for(int num : piles) max_num = max(max_num, num);
        int l = 1, r = max_num;
        int ans = -1;
        while(l <= r) {
            int k = l + (r - l) / 2;
            long long time = 0;
            for(int num : piles) {
                time += ceil((double)num / k); //time += (num + k - 1) / k;
                //if(time > h) break;
            }
            if(time > h) l = k + 1;
            else { 
                ans = k;
                r = k - 1;
            }
        }
        return ans;
    }
};