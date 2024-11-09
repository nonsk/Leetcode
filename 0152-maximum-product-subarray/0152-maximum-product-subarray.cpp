class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int max = INT_MIN;
        int product = 1;
        for (int i = 0; i < n; i++) {
            product = 1;
            for (int j = i; j < n; j++) {
                product = product * nums[j];
                if (max < product) {
                    max = product;
                }
            }
        }
        return max;
    }
};