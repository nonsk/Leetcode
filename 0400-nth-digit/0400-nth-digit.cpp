class Solution {
public:
    int findNthDigit(int n) {
        string str = "";
        int count = 1;;
        while(str.size()<=n+1){
            str += to_string(count);
            count++;
        }
        return str[n-1]-'0';
    }
};