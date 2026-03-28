class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size();
        int median = (size1 + size2) / 2 + 1;
        int extra;
        int res;
        int count = 0;
        bool done = false;
        int a = 0, b = 0;
        while(a < size1 && b < size2) {
            int start, end;
            int check_arr = 0;
            if(nums1[a] <= nums2[b]) {
                int target = nums2[b];
                int l = a; int r = size1 - 1;
                while(l <= r) {
                    int m = l + (r - l) / 2;
                    if(nums1[m] > target) r = m - 1;
                    else l = m + 1;  
                }
                start = a; end = r;
                a = r + 1;
            }
            else {
                int target = nums1[a];
                int l = b; int r = size2 - 1;
                while(l <= r) {
                    int m = l + (r - l) / 2;
                    if(nums2[m] > target) r = m - 1;
                    else l = m + 1;  
                }
                start = b; end = r;
                check_arr = 1;
                b = r + 1;
            }
            int range = end - start + 1;
            if(count + range < median) {
                if(!check_arr) extra = nums1[end];
                else extra = nums2[end];
                count += range;
            }
            else {
                int ptr = median - count - 1;
                if(!check_arr) {
                    res = nums1[start + ptr];
                    if(ptr) extra = nums1[start + ptr - 1];
                }
                else {
                    res = nums2[start + ptr];
                    if(ptr) extra = nums2[start + ptr - 1];
                }
                done = true;
                break;
            }
        }
        if(!done && a < size1) {
            int ptr = median - count - 1;
            res = nums1[a + ptr];
            if(ptr) extra = nums1[a + ptr - 1];
        }
        if(!done && b < size2) {
            int ptr = median - count - 1;
            res = nums2[b + ptr];
            if(ptr) extra = nums2[b + ptr - 1];
        }
        if((size1 + size2) % 2) return (double)res;
        else return ((double)res + extra) / 2;
    }
};

// 1 3 7     6 8 10
