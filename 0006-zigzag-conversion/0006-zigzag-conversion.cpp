class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if (numRows == 1 || numRows >= n) return s;

        string res;
        res.reserve(n);

        int cycle = 2 * numRows - 2;

        for (int r = 0; r < numRows; ++r) {
            if (r == 0 || r == numRows - 1) {
                for (int i = r; i < n; i += cycle) {
                    res.push_back(s[i]);
                }
            } else {
                int step1 = cycle - 2 * r;
                int step2 = 2 * r;
                int i = r;

                while (i < n) {
                    res.push_back(s[i]);
                    i += step1;

                    if (i < n) {
                        res.push_back(s[i]);
                        i += step2;
                    }
                }
            }
        }

        return res;
    }
};