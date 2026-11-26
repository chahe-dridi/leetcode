class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        char buf[17]; // max 2*8 = 16 + null? Actually we use emplace_back with len, so no null needed but safe.
        backtrack(res, buf, 0, 0, 0, n);
        return res;
    }
private:
    void backtrack(vector<string>& res, char* buf, int open, int close, int len, int n) {
        if (len == 2 * n) {
            res.emplace_back(buf, len);
            return;
        }
        if (open < n) {
            buf[len] = '(';
            backtrack(res, buf, open + 1, close, len + 1, n);
        }
        if (close < open) {
            buf[len] = ')';
            backtrack(res, buf, open, close + 1, len + 1, n);
        }
    }
};