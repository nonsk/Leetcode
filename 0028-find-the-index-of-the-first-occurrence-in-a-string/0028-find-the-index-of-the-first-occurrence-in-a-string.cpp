class Solution {
public:
    int strStr(const string& haystack, const string& needle) {
        // Edge case: if needle is empty, return 0.
        if (needle.empty()) return 0;

        int hSize = haystack.size();
        int nSize = needle.size();

        // Edge case: if needle is longer than haystack, return -1.
        if (nSize > hSize) return -1;

        // Iterate over the haystack, only until there's enough room left for the needle.
        for (int i = 0; i <= hSize - nSize; ++i) {
            // Check if the substring starting at i matches the needle.
            if (haystack.substr(i, nSize) == needle) {
                return i; // Found the starting index.
            }
        }

        // If no match is found, return -1.
        return -1;
    }
};
