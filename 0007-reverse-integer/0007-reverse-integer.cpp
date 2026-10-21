class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x) {
            int pop = x % 10;
            if (res > 214748364 || res < -214748364) return 0;
            if (res == 214748364 && pop > 7) return 0;
            if (res == -214748364 && pop < -8) return 0;
            res = res * 10 + pop;
            x /= 10;
        }
        return res;
    }
};