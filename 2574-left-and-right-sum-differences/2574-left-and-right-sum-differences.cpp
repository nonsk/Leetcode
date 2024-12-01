class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
    vector<int> leftSum(n, 0), rightSum(n, 0), result(n, 0);

    // Calculate left sums
    for (int i = 1; i < n; ++i) {
        leftSum[i] = leftSum[i - 1] + nums[i - 1];
    }

    // Calculate right sums
    for (int i = n - 2; i >= 0; --i) {
        rightSum[i] = rightSum[i + 1] + nums[i + 1];
    }

    // Calculate absolute differences
    for (int i = 0; i < n; ++i) {
        result[i] = abs(leftSum[i] - rightSum[i]);
    }

    return result;
    }
};