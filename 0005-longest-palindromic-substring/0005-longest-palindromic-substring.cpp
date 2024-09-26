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
        return true;
    }
    string longestPalindrome(string s) {
        string ans = "";
        int i;
        int j;
        pair <int,int> p = {0,0};
        for (i = 0; i < s.size(); i++) {
            for (j = s.size() - 1; j >= i; j--) {

                if(j<p.second&&i>p.first){
                    break;
                }
                if(p.second-p.first > j-i){
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