class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if (numRows == 1 || numRows >= n) return s;

        string res(n, ' ');
        char* dst = &res[0];
        const char* src = s.data();

        int cycle = 2 * numRows - 2;
        int pos = 0;

        for (int i = 0; i < n; i += cycle) {
            dst[pos++] = src[i];
        }

        for (int r = 1; r < numRows - 1; ++r) {
            int step1 = cycle - 2 * r;
            int step2 = 2 * r;
            int i = r;

            while (i < n) {
                dst[pos++] = src[i];
                i += step1;
                if (i >= n) break;
                dst[pos++] = src[i];
                i += step2;
            }
        }

        for (int i = numRows - 1; i < n; i += cycle) {
            dst[pos++] = src[i];
        }

        return res;
    }
};