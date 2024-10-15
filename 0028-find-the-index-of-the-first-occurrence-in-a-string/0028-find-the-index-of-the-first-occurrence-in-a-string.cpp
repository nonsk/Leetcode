class Solution {
public:
    int strStr(const string& haystack, const string& needle) {
        int hSize = haystack.size();
        int nSize = needle.size();

        
        if (nSize == 0) return 0;
        
        if (nSize > hSize) return -1;

        
        vector<int> lps = buildLPS(needle);

        int i = 0, j = 0;  
        while (i < hSize) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
                
                if (j == nSize) return i - j;
            } else if (j > 0) {
                j = lps[j - 1];  
            } else {
                i++;  
            }
        }

        return -1; 
    }

private:
    // Helper function to build the LPS array.
    vector<int> buildLPS(const string& needle) {
        int nSize = needle.size();
        vector<int> lps(nSize, 0);
        int len = 0;  

        for (int i = 1; i < nSize; ) {
            if (needle[i] == needle[len]) {
                lps[i++] = ++len;
            } else if (len > 0) {
                len = lps[len - 1]; 
            } else {
                lps[i++] = 0;  
            }
        }
        return lps;
    }
};
