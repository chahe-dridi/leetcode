class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = (int)height.size() - 1;
        int best = 0;

        while (l < r) {
            int hl = height[l];
            int hr = height[r];
            int h = hl < hr ? hl : hr;
            int area = h * (r - l);
            if (area > best) best = area;

            if (hl < hr) {
                ++l;
            } else if (hl > hr) {
                --r;
            } else {
                ++l;
                --r;
            }
        }

        return best;
    }
};