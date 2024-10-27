class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int maxLength = 0;
        int i = 0;
        
        for (int j = 0; j < s.size(); j++) { 
            while (st.find(s[j]) != st.end()) { 
                st.erase(s[i]); 
                i++; 
            }
            st.insert(s[j]); 
            maxLength = max(maxLength, j - i + 1); 
        }
        
        return maxLength;
    }
};
