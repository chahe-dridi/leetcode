class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last[256] = {0};
        int left = 0, best = 0;
        const int n = s.size();
        
        for (int i = 0; i < n; ++i) {
            const int c = (unsigned char)s[i];
            const int prev = last[c];
            
            if (prev > left) {
                left = prev;
            } else {
                const int len = i - left + 1;
                if (len > best) best = len;
            }
            last[c] = i + 1;
            
            if (best >= n - left) return best;
        }
        return best;
    }
};