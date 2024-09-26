class Solution {
public:
    bool palcheck(string& s, int i, int j) {
        int r = j;
        int l = i;
        while (r > l) {
            if (s[l] != s[r]) {

                return false;
            }
            r--;
            l++;
        }
        // if (a.second - a.first < j - i) {
        //     a.first = i;
        //     a.second = j;
        // }
        return true;
    }

    // bool solve(string s, int i, int j, pair<int, int>& a,
    //             vector<vector<int>>& dp) {
    //     if (i > j) {
    //         return false;
    //     }
    //     if (dp[i][j] != -1) {
    //         return dp[i][j];
    //     }

    //     // if (a.second - a.first > j - i) {
    //     //     return false;
    //     // }
    //     // if (i >= a.first && j <= a.second) {
    //     //     return false;
    //     // }
    //     if (s == "") {
    //         return true;
    //     }

    //     if (palcheck(s, i, j, a, dp)) {
    //         dp[i][j] = 1;
    //         return true;
    //     } else if (solve(s, i + 1, j, a, dp)){
    //         dp[i + 1][j] = 1;
    //         return true;

    //     } else if (solve(s, i, j - 1, a, dp)){
    //         dp[i][j - 1] = 1;
    //         return true;
    //     }
    //     else {
    //         dp[i][j] = 0;
    //         return false;}
    // }
    string longestPalindrome(string s) {
        // pair<int, int> a = {0, 0};
        // vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, -1));
        // bool flag = solve(s, 0, s.size(), a, dp);
        string ans = "";
        int i;
        int j;
        pair <int,int> p = {0,0};
        for (i = 0; i < s.size(); i++) {
            for (j = s.size() - 1; j >= i; j--) {

                if(j<p.second&&i>p.first){
                    // i = p.second;
                    break;
                }
                if (palcheck(s, i, j)) {
                    if(p.second-p.first < j-i){
                        p.first = i;
                        p.second = j;
                    }
                }
            }
        }
        for (int pr = p.first; pr <= p.second; pr++) {
            ans = ans+s[pr];
        }
        return ans;
    }
};