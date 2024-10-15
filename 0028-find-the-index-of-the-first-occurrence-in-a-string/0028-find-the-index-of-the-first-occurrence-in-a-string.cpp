class Solution {
public:
    int strStr(string haystack, string needle) {
        int ans = -1;
        string temp = needle;
        for (int i = 0; i < haystack.size(); i++) {
            cout<<temp<<endl;
            if (haystack[i] == temp[0]) {
                ans = i;
                temp = temp.substr(1, temp.size()-1);
            } else {
                temp = needle;
                ans = -1;
            }
            if (temp.size() == 0) {
                return i-needle.size()+1;
            }
        }
        if(temp.size()!=0){
            return -1;
        }
        return ans;
    }
};