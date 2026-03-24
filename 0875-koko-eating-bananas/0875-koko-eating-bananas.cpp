class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_num = -1;
        for(int num : piles) max_num = max(max_num, num);
        int l = 1, r = max_num;
        int ans = -1;
        while(l <= r) {
            int k = l + (r - l) / 2;
            int sum = 0;
            for(int num : piles) {
                sum += ceil((double)num / k);
                if(sum > h) break;
            }
            if(sum > h) l = k + 1;
            else { 
                ans = k;
                r = k - 1;
            }
        }
        return ans;
    }
};
