class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
    int closest_sum = INT_MAX / 2; // Initialize with a large value

    for (int i = 0; i < nums.size() - 2; ++i) {
        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            int current_sum = nums[i] + nums[left] + nums[right];
            if (abs(target - current_sum) < abs(target - closest_sum)) {
                closest_sum = current_sum;
            }

            if (current_sum < target) {
                ++left;
            } else if (current_sum > target) {
                --right;
            } else {
                return target; // Exact match
            }
        }
    }

    return closest_sum;
    }
};