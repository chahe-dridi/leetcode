class Solution {
public:
    int myAtoi(string s) {
        const char* p = s.data();
        int n = s.size(), i = 0;
        while (i < n && p[i] == ' ') ++i;

        int sign = 1;
        if (i < n && (p[i] == '+' || p[i] == '-')) {
            if (p[i] == '-') sign = -1;
            ++i;
        }

        long long res = 0;
        while (i < n && p[i] >= '0' && p[i] <= '9') {
            res = res * 10 + (p[i] - '0');
            if (res > 2147483648LL) {
                res = 2147483648LL;
                break;
            }
            ++i;
        }

        if (sign == 1) return res > INT_MAX ? INT_MAX : (int)res;
        return res >= 2147483648LL ? INT_MIN : -(int)res;
    }
};