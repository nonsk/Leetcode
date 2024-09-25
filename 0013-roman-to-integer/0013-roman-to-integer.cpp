class Solution {
public:
    int romanToInt(string s) {
        int count = 0;
        vector<int> ans(s.size(), 0);

        for (int i = 0; i < s.size(); i++) {
            switch (s[i]) {
            case 'I':
                ans[i] = 1;
                break;
            case 'V':
                ans[i] = 5;
                break;
            case 'X':
                ans[i] = 10;
                break;
            case 'L':
                ans[i] = 50;
                break;
            case 'C':
                ans[i] = 100;
                break;
            case 'D':
                ans[i] = 500;
                break;
            case 'M':
                ans[i] = 1000;
                break;
            }
        }
        count = count + ans[0];
        for (int i = 1; i < s.size(); i++) {
            if (ans[i] <= ans[i - 1]) {
                count = count + ans[i];
            } else {
                count = count - 2 * ans[i - 1] + ans[i];
            }
        }
        return count;
    }
};