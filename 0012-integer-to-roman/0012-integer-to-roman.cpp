class Solution {
public:
    string intToRoman(int num) {
        static const char* thousands[] = {"", "M", "MM", "MMM"};
        static const char* hundreds[]  = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        static const char* tens[]      = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        static const char* ones[]      = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

        string res;
        res.reserve(15);
        res += thousands[num / 1000];
        res += hundreds[(num / 100) % 10];
        res += tens[(num / 10) % 10];
        res += ones[num % 10];
        return res;
    }
};