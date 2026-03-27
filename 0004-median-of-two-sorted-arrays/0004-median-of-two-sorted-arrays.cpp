class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<int> nums;
        int a = 0, b = 0;
        while(a < m && b < n) {
            if(nums1[a] <= nums2[b]) {
                nums.push_back(nums1[a]);
                a++;
            }
            else {
                nums.push_back(nums2[b]);
                b++;
            }
        }
        while(a < m) {
            nums.push_back(nums1[a]);
            a++;
        }
        while(b < n) {
            nums.push_back(nums2[b]);
            b++;
        }
        int len = m + n;
        if(!(len % 2)) {
            double avg = (double)(nums[len / 2 - 1] + nums[len / 2]) / 2;
            return avg;
        }
        else return nums[len / 2];
    }
};
