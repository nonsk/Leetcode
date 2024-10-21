class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        if(columnNumber<27){
            ans = ans + (char)(columnNumber + 64);
            return ans;
        }
        int last = columnNumber%26;
        if(last==0){
            return convertToTitle(columnNumber/26-1)+convertToTitle(26);
        }
        return convertToTitle(columnNumber/26)+convertToTitle(last);
    }
};