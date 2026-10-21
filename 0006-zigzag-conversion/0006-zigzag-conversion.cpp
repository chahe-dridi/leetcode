class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if (numRows == 1 || numRows >= n) return s;
        
        string res;
        res.reserve(n);
        
        int cycle = 2 * numRows - 2;
        
        for (int i = 0; i < n; i += cycle) {
            res.push_back(s[i]);
        }
        
        for (int r = 1; r < numRows - 1; ++r) {
            int step1 = cycle - 2 * r;
            for (int i = r; i < n; i += cycle) {
                res.push_back(s[i]);
                int next = i + step1;
                if (next < n) {
                    res.push_back(s[next]);
                }
            }
        }
        
        for (int i = numRows - 1; i < n; i += cycle) {
            res.push_back(s[i]);
        }
        
        return res;
    }
};