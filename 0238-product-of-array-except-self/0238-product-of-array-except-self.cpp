class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        int count = 0;
        for (auto mult : nums) {
            if (mult == 0) {
                count++;
                continue;
            }
            prod *= mult;
        }
        vector<int> answer(nums.size(), 0);
        if (count > 1) {
            return answer;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                vector<int> answer2(nums.size(), 0);
                answer2[i] = prod;
                return answer2;
            }
            answer[i] = prod / nums[i];
        }
        return answer;
    }
};