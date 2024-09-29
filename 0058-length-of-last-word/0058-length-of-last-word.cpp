class Solution {
public:
    int lengthOfLastWord(string s) {
        int count=0;
        int n = s.size();
        while(s[s.size()-1]==' ') {s.pop_back();}
        if(s.size()==1){return 1;}
        n = s.size();
        while(count!=n&&s[n-count-1]!=' '){
            count++;
        }
        return count;
    }
};