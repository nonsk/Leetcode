class Solution {
public:
    int maximumProduct(vector<int>& nums) {
         // Sort the array
    sort(nums.begin(), nums.end());
    
    int n = nums.size();
    
    // Compute the two possibilities
    int option1 = nums[n-1] * nums[n-2] * nums[n-3]; // Product of three largest numbers
    int option2 = nums[0] * nums[1] * nums[n-1];     // Product of two smallest and largest number
    
    // Return the maximum of the two
    return max(option1, option2);
    }
};