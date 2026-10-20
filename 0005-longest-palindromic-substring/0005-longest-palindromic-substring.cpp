class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) return s;
        
        int start = 0, maxLen = 1;
        const char* str = s.data();
        
        for (int i = 0; i < n; ) {
            int l = i, r = i;
            while (r < n - 1 && str[r] == str[r + 1]) {
                ++r;
            }
            
            int next_i = r + 1;
            
            while (l > 0 && r < n - 1 && str[l - 1] == str[r + 1]) {
                --l;
                ++r;
            }
            
            int len = r - l + 1;
            if (len > maxLen) {
                maxLen = len;
                start = l;
            }
            
            i = next_i;
        }
        
        return s.substr(start, maxLen);
    }
};