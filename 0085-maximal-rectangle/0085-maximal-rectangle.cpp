class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();

        // A single array to store the width of consecutive '1's up to each column in the current row
        vector<int> width(n, 0);
        int maxArea = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Update the width for the current row
                width[j] = (matrix[i][j] == '1') ? width[j] + 1 : 0;
            }

            // Calculate the maximal rectangle for the current row
            for (int j = 0; j < n; j++) {
                if (width[j] > 0) {
                    int minWidth = width[j];
                    // Check up to the current row to find the maximal area
                    for (int k = j; k >= 0 && width[k] > 0; k--) {
                        minWidth = min(minWidth, width[k]);
                        int area = minWidth * (j - k + 1);
                        maxArea = max(maxArea, area);
                    }
                }
            }
        }

        return maxArea;
    }
};
