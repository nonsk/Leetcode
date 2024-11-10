class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_to_index; // Map to store each number and its index
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i]; // Calculate the required complement
        if (num_to_index.find(complement) != num_to_index.end()) {
            // If complement is found in map, return the indices
            return {num_to_index[complement], i};
        }
        num_to_index[nums[i]] = i; // Store the current number with its index
    }
    return {}; // Return an empty vector if no solution is found (should not happen per problem statement)
    }
};