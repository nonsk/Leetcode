class Solution {
public:
    int calculate(string s) {
        int result = 0;
        int current = 0;
        int num = 0;
        char o = '+';
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '(') {
                int br = 1;
                string bracket = "";
                i++;
                while (br != 0) {
                    if (s[i] == '(') {
                        br++;
                    }
                    if (s[i] == ')') {
                        br--;
                    }
                    bracket += s[i];
                    i++;
                }
                i--;
                num = calculate(bracket.substr(0,bracket.size()-1));
            }
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            if (!isdigit(c) && c != ' ' || i == s.size() - 1) {
                if (o == '+') {
                    result += current;
                    current = num;
                } else if (o == '-') {
                    result += current;
                    current = -num;
                } else if (o == '*') {
                    current *= num;
                } else if (o == '/') {
                    current /= num;
                }
                o = c;
                num = 0;
            }
        }
        result += current;
        return result;
    }
};
