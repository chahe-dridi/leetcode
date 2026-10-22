class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<char> dp(m + 1, 0), next(m + 1, 0);
        dp[0] = 1;

        for (int j = 1; j <= m; ++j) {
            if (p[j - 1] == '*') {
                dp[j] = dp[j - 2];
            }
        }

        for (int i = 1; i <= n; ++i) {
            next[0] = 0;

            for (int j = 1; j <= m; ++j) {
                if (p[j - 1] == '*') {
                    next[j] = next[j - 2] ||
                              (dp[j] && (p[j - 2] == '.' || p[j - 2] == s[i - 1]));
                } else {
                    next[j] = dp[j - 1] &&
                              (p[j - 1] == '.' || p[j - 1] == s[i - 1]);
                }
            }

            dp.swap(next);
        }

        return dp[m];
    }
};