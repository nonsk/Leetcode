class Solution {
public:
    bool isNumber(string s) {
        bool decimal = true;
        bool sign = true;
        bool e = true;
        bool virgin = true;
        for (int i = 0; i < s.size(); i++) {

            // sign
            if (s[i] == '+' || s[i] == '-') {
                if (i == s.size() - 1) {
                    return false;
                }
                if (!sign) {
                    return false;
                }
                sign = false;
                continue;
            }

            // number
            if (s[i] >= '0' && s[i] <= '9') {
                virgin = false;
                sign = false;
                continue;
            }

            // decimal
            if (s[i] == '.') {
                if(!isNumber(s.substr(1,s.size()-1))){
                    return false;
                }
                if (!decimal) {
                    return false;
                }
                if (s.size() == 1) {
                    return false;
                }
                sign = false;
                decimal = false;
                continue;
            }

            // expo
            if (s[i] == 'e' || s[i] == 'E') {
                if (i == s.size() - 1) {
                    return false;
                }
                if (!e) {
                    return false;
                }
                sign = true;
                e = false;
                decimal = false;
                if (i == s.size() - 1) {
                    return false;
                }
                if (virgin) {
                    return false;
                }
                if (e > 1) {
                    return false;
                }
                continue;
            }

            // rest
            return false;
        }
        return true;
    }
};