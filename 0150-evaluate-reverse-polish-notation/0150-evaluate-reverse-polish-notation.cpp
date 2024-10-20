class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int ans = 0;
        for (auto it : tokens) {
            if (it == "+") {
                int one = s.top();
                s.pop();
                if (!s.empty()) {
                    ans = s.top();
                    s.pop();
                }
                ans = one + ans;
                s.push(ans);

            } else if (it == "-") {
                int one = s.top();
                s.pop();
                if (!s.empty()) {
                    ans = s.top();
                    s.pop();
                }
                ans = ans - one;
                s.push(ans);

            } else if (it == "*") {
                ans = s.top();
                s.pop();
                int n = s.top();
                s.pop();
                ans = n * ans;
                s.push(ans);

            } else if (it == "/") {
                ans = s.top();
                s.pop();
                int n = s.top();
                s.pop();
                ans = n / ans;
                s.push(ans);
            } else {
                int num = stoi(it);
                s.push(num);
            }
        }
        if (!s.empty()) {
            ans = s.top();
            s.pop();
        }
        return ans;
    }
};