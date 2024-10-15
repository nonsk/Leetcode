class Solution {
public:
    int strStr(const string& haystack, const string& needle) {
        int hSize = haystack.size();
        int nSize = needle.size();

        // Edge case: if the needle is empty, return 0.
        if (nSize == 0) return 0;
        // If needle is longer than haystack, return -1.
        if (nSize > hSize) return -1;

        // Create the LPS array in-place with minimal memory usage.
        int lps[nSize];  // Using stack memory instead of heap-allocated vector.
        buildLPS(needle, lps);  // Build the LPS array.

        // Perform the search with two pointers.
        int i = 0, j = 0;  // i: index for haystack, j: index for needle.
        while (i < hSize) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
                // If we matched the entire needle, return the starting index.
                if (j == nSize) return i - j;
            } else if (j > 0) {
                j = lps[j - 1];  // Use LPS to skip unnecessary comparisons.
            } else {
                i++;  // No match and j == 0, move to the next character in haystack.
            }
        }

        return -1;  // No match found.
    }

private:
    // Build the LPS array in-place to minimize memory usage.
    void buildLPS(const string& needle, int lps[]) {
        int nSize = needle.size();
        int len = 0;  // Length of the previous longest prefix suffix.
        lps[0] = 0;  // LPS value for the first character is always 0.

        for (int i = 1; i < nSize; ) {
            if (needle[i] == needle[len]) {
                len++;
                lps[i] = len;
                i++;
            } else if (len > 0) {
                len = lps[len - 1];  // Use the previous LPS value.
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
};
