class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int n = (int)s.size();
        int last[256] = {0};
        int left = 0;
        int best = 0;

        for (int right = 0; right < n; ++right) {
            const unsigned char c = s[right];
            const int prev = last[c];
            if (prev > left) left = prev;
            last[c] = right + 1;
            const int len = right - left + 1;
            if (len > best) best = len;
        }

        return best;
    }
};