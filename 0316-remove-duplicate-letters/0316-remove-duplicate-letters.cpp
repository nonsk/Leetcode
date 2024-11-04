class Solution {
public:
    string removeDuplicateLetters(string s) {
      vector<int> index (26, -1);
      vector<bool> check (26, false);
      stack <char> st;
      for(int i =0; i<s.size(); i++){
        index[s[i] - 'a'] = i;
      }
      for(int i = 0; i < s.size(); i++){
        if(check[s[i] - 'a']){continue;}
        while(!st.empty() && i < index[st.top() - 'a'] && s[i]<st.top()){
            check[st.top() - 'a'] = false;
            st.pop();
        }
        st.push(s[i]);
        check[s[i] - 'a'] = true;
      }
      string ans = "";
      while(!st.empty()){
        ans += st.top();
        st.pop();
      }
      reverse(ans.begin(), ans.end());
      return ans;
    }
};