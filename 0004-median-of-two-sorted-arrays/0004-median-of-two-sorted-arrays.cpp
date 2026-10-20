class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        const int m = (int)nums1.size();
        const int n = (int)nums2.size();
        const int total = m + n;
        const int half = total / 2;

        int lo = 0, hi = m;

        while (lo <= hi) {
            const int i = lo + (hi - lo) / 2;
            const int j = half - i;

            const int left1  = (i == 0) ? INT_MIN : nums1[i - 1];
            const int right1 = (i == m) ? INT_MAX : nums1[i];
            const int left2  = (j == 0) ? INT_MIN : nums2[j - 1];
            const int right2 = (j == n) ? INT_MAX : nums2[j];

            if (left1 <= right2 && left2 <= right1) {
                if (total & 1)
                    return std::min(right1, right2);

                return (std::max(left1, left2) + std::min(right1, right2)) / 2.0;
            }

            if (left1 > right2)
                hi = i - 1;
            else
                lo = i + 1;
        }

        return 0.0;
    }
};