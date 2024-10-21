class Solution {
public:
    int calculate(string s) {
        int result = 0, current = 0, num = 0;
        char operation = '+';
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            if (!isdigit(c) && c != ' ' || i == s.size() - 1) {
                if (operation == '+') {
                    result += current;
                    current = num;  
                } else if (operation == '-') {
                    result += current;
                    current = -num;  
                } else if (operation == '*') {
                    current *= num;  
                } else if (operation == '/') {
                    current /= num;  
                }   
                operation = c;
                num = 0;
            }
        }
        result += current;
        return result;
    }
};
