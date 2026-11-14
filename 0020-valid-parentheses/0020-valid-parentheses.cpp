class Solution {
public:
    bool isValid(string s) {
        if (s.size() & 1) return false;
        
        char stack[10001];
        int top = 0;
        
        char match[128] = {0};
        match[')'] = '(';
        match[']'] = '[';
        match['}'] = '{';
        
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stack[top++] = c;
            } else {
                if (top == 0 || stack[top - 1] != match[c]) {
                    return false;
                }
                --top;
            }
        }
        
        return top == 0;
    }
};