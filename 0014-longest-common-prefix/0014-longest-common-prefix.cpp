class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        for (int i = 0; ; ++i) {
            if (i == strs[0].size()) {
                return strs[0];
            }
            
            char c = strs[0][i];
            
            for (int j = 1; j < strs.size(); ++j) {
                if (i == strs[j].size() || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
    }
};