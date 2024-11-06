class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        // Step 1: Sort the numbers to ensure each element can be divisible by its predecessors
        sort(nums.begin(), nums.end());

        // Step 2: Create arrays to store the largest subset length and previous element index for tracing
        vector<int> dp(n, 1), prev(n, -1);

        int maxIndex = 0; // Index of the largest element in the longest subset

        // Step 3: Populate dp and prev arrays
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            // Update maxIndex if we found a longer subset ending at i
            if (dp[i] > dp[maxIndex]) {
                maxIndex = i;
            }
        }

        // Step 4: Reconstruct the largest divisible subset using the prev array
        vector<int> ans;
        for (int i = maxIndex; i >= 0; i = prev[i]) {
            ans.push_back(nums[i]);
            if (prev[i] == -1) break; // Reached the beginning of the subset
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
