class Solution {
public:
    int romanToInt(string s) {
        int val[128] = {0};
        val['I'] = 1;
        val['V'] = 5;
        val['X'] = 10;
        val['L'] = 50;
        val['C'] = 100;
        val['D'] = 500;
        val['M'] = 1000;

        int res = 0;
        int prev = 0;

        for (int i = (int)s.size() - 1; i >= 0; --i) {
            int curr = val[s[i]];
            if (curr < prev) {
                res -= curr;
            } else {
                res += curr;
                prev = curr;
            }
        }

        return res;
    }
};