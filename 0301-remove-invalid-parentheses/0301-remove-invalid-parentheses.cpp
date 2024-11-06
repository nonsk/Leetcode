class Solution {
public:
    int maxlen;
    string main;
    string chars;
    bool valid(string s) {
        int balance = 0;
        for (char c : s) {
            if (c == '(') {
                balance++;
            } else if (c == ')') {
                if (balance == 0) return false;
                balance--;
            }
        }
        return balance == 0;
    }
    void generate(int valid_open, int valid_close, int t_char, unordered_set<string>& ans,
                  string& curr, int index) {
        if (valid_open < 0 || valid_close < 0 || t_char < 0 || index > main.size()) {
            return;
        }
        if (curr.size() == maxlen) {
            if (valid(curr)) {
                ans.insert(curr);
            }
            return;
        }
        int len = curr.size();
        if (main[index] == '(') {
            curr += '(';
            generate(valid_open - 1, valid_close, t_char, ans, curr, index + 1);
            curr.resize(len);
        } else if (main[index] == ')') {
            curr += ')';
            generate(valid_open, valid_close - 1, t_char, ans, curr, index + 1);
            curr.resize(len);
        } else {
            curr += main[index];
            generate(valid_open, valid_close, t_char - 1, ans, curr, index + 1);
            curr.resize(len);
        }
        generate(valid_open, valid_close, t_char, ans, curr, index + 1);
    }
    vector<string> removeInvalidParentheses(string s) {
        main = s;
        unordered_set<string> ans;
        int open = 0, close = 0, t_open = 0, t_close = 0, t_char = 0;
        for (char c : s) {
            if (c == '(') {
                t_open++;
                open++;
            } else if (c == ')') {
                t_close++;
                if (open > 0) {
                    open--;
                } else {
                    close++;
                }
            } else {
                chars += c;
                t_char++;
            }
        }

        int valid_open = max(0, t_open - open);
        int valid_close = max(0, t_close - close);
        maxlen = s.size() - open - close;
        string curr;
        generate(valid_open, valid_close, t_char, ans, curr, 0);
        return vector<string>(ans.begin(), ans.end());
    }
};
