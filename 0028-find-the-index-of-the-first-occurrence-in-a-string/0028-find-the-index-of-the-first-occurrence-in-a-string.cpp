class Solution {
public:
    int strStr(const string& haystack, const string& needle) {
        
        if (needle.empty()) return 0;

        int hSize = haystack.size();
        int nSize = needle.size();

        
        if (nSize > hSize) return -1;

        
        for (int i = 0; i <= hSize - nSize; ++i) {
            
            if (haystack.substr(i, nSize) == needle) {
                return i; 
            }
        }

        
        return -1;
    }
};
