class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        static const char* mp[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        static const int lens[10] = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4};
        int total = 1;
        for (char d : digits) total *= lens[d - '0'];
        vector<string> res;
        res.reserve(total);
        string cur(digits.size(), ' ');
        auto dfs = [&](auto&& self, int idx) -> void {
            if (idx == (int)digits.size()) {
                res.push_back(cur);
                return;
            }
            const char* letters = mp[digits[idx] - '0'];
            int len = lens[digits[idx] - '0'];
            for (int i = 0; i < len; ++i) {
                cur[idx] = letters[i];
                self(self, idx + 1);
            }
        };
        dfs(dfs, 0);
        return res;
    }
};