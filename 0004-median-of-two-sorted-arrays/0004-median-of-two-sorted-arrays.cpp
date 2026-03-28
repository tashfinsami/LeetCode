class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size();
        int median = (size1 + size2) / 2 + 1;
        vector<int> res(2);
        int count = 0;
        bool done = false;
        int a = 0, b = 0;
        while(a < size1 && b < size2) {
            bool check_arr1;
            if(nums1[a] <= nums2[b]) check_arr1 = true;
            else check_arr1 = false;
            int l = (check_arr1) ? a : b;
            int r = (check_arr1) ? size1 - 1 : size2 - 1;
            int target = (check_arr1) ? nums2[b] : nums1[a];
            vector<int>& temp = (check_arr1) ? nums1 : nums2;
            while(l <= r) {
                int m = l + (r - l) / 2;
                if(temp[m] > target) r = m - 1;
                else l = m + 1;  
            }
            int start = (check_arr1) ? a : b, end = r;
            if(check_arr1) a = r + 1;
            else b = r + 1;
            int range = end - start + 1;
            if(count + range < median) {
                res[0] = temp[end];
                count += range;
            }
            else {
                int ptr = median - count - 1;
                res[1] = temp[start + ptr];
                if(ptr > 0) res[0] = temp[start + ptr - 1];
                done = true;
                break;
            }
        }
        if(!done && a < size1) {
            int ptr = median - count - 1;
            res[1] = nums1[a + ptr];
            if(ptr > 0) res[0] = nums1[a + ptr - 1];
        }
        if(!done && b < size2) {
            int ptr = median - count - 1;
            res[1] = nums2[b + ptr];
            if(ptr > 0) res[0] = nums2[b + ptr - 1];
        }
        return ((size1 + size2) % 2) ? (double)res[1] : (double)(res[0] + res[1]) / 2;
    }
};

// 1 3 7     6 8 10
