class Solution {
public:
    int maxlen;
    string chars;
    string main;

    bool isValid(string& s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(') {
                st.push(c);
            } else if (c == ')') {
                if (!st.empty()) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }

    void f(int valid_open, int valid_close, int t_char, unordered_set<string>& ans,
                  string curr, const string& chars, int index) {
        if (valid_open < 0 || valid_close < 0 || t_char < 0 || index > main.size()) {
            return;
        }
        if (curr.size() == maxlen) {
            if (isValid(curr)) {
                ans.insert(curr);
            }
            return;
        }

        if (main[index] == '(') {
            f(valid_open - 1, valid_close, t_char, ans, curr + '(', chars, index + 1);
        } else if (main[index] == ')') {
            f(valid_open, valid_close - 1, t_char, ans, curr + ')', chars, index + 1);
        } else if (!chars.empty()) {
            f(valid_open, valid_close, t_char - 1, ans, curr + chars[0], chars.substr(1), index + 1);
        }
        f(valid_open, valid_close, t_char, ans, curr, chars, index + 1);
    }

    vector<string> removeInvalidParentheses(string s) {
        main = s;
        stack<char> st;
        unordered_set<string> ans;
        int open = 0, close = 0, t_open = 0, t_close = 0, t_char = 0;

        for (char c : s) {
            if (c == '(') {
                t_open++;
                st.push(c);
            } else if (c == ')') {
                t_close++;
                if (!st.empty()) {
                    st.pop();
                } else {
                    close++;
                }
            } else {
                chars += c;
                t_char++;
            }
        }

        open = st.size();
        int valid_open = max(0, t_open - open);
        int valid_close = max(0, t_close - close);
        maxlen = s.size() - open - close;
        f(valid_open, valid_close, t_char, ans, "", chars, 0);
        return vector<string>(ans.begin(), ans.end());
    }
};
