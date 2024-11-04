#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < nums.size() - 1 && nums[l] <= nums[l + 1]) {
            l++;
        }
        if (l == nums.size() - 1) return 0;
        while (r > 0 && nums[r] >= nums[r - 1]) {
            r--;
        }
        int subarrayMin = *min_element(nums.begin() + l, nums.begin() + r + 1);
        int subarrayMax = *max_element(nums.begin() + l, nums.begin() + r + 1);
        while (l > 0 && nums[l - 1] > subarrayMin) {
            l--;
        }
        while (r < nums.size() - 1 && nums[r + 1] < subarrayMax) {
            r++;
        }
        
        return r - l + 1;
    }
};
