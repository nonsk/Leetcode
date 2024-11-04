class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int third = INT_MIN;
        stack<int> stack;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] < third) {
                return true;
            }
            while (!stack.empty() && stack.top() < nums[i]) {
                third = stack.top();
                stack.pop();
            }
            stack.push(nums[i]);
        }
        return false;
    }
};