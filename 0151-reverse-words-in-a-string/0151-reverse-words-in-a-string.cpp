class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp = "";
        
        for (int it = 1; it <= s.size(); it++) {
            if (s[it] == ' '&&s[it-1] == ' ') {
                it--;
              s.erase(it,1);
            }
        }
        if(s[0]==' '){
                          s.erase(0,1);
        }
        cout<<s<<endl;
        for (int it = 0; it <= s.size(); it++) {
            if (s[it] == ' ') {
                st.push(temp);
                cout << temp << endl;
                temp = "";
                continue;
            }
            if(temp.size()!=0&&it==s.size()){
                          st.push(temp);
            }
            temp += s[it];
        }
        string ans;
        while (!st.empty()) {
            ans += st.top();
            ans += ' ';
            st.pop();
        }
ans.erase(ans.size()-1,1);
        return ans;
    }
};