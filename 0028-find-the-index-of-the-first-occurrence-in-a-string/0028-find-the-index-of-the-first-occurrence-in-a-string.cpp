class Solution {
public:
    int strStr(const string& haystack, const string& needle) {
        int hSize = haystack.size();
        int nSize = needle.size();

        // Edge case: Empty needle.
        if (nSize == 0) return 0;
        // If needle is longer than haystack, return -1.
        if (nSize > hSize) return -1;

        // Create the bad character shift table (ASCII size of 256).
        int badChar[256];
        buildBadCharTable(needle, badChar);

        int shift = 0;  // Shift for the haystack window.

        while (shift <= hSize - nSize) {
            int j = nSize - 1;

            // Compare the needle from right to left.
            while (j >= 0 && needle[j] == haystack[shift + j]) {
                j--;
            }

            // If the needle is found, return the starting index.
            if (j < 0) {
                return shift;
            }

            // Shift the pattern to align with the next potential match.
            shift += max(1, j - badChar[haystack[shift + j]]);
        }

        return -1;  // No match found.
    }

private:
    // Helper function to build the bad character table.
    void buildBadCharTable(const string& needle, int badChar[256]) {
        // Initialize all entries to -1.
        fill(badChar, badChar + 256, -1);

        // Fill in the actual indices of characters in the needle.
        for (int i = 0; i < needle.size(); ++i) {
            badChar[needle[i]] = i;
        }
    }
};
