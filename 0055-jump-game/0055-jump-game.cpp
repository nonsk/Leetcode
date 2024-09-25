class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int goal = n-1;
        for(int i = n-1; i>=0; i--){
            if(nums[i]+i>=goal){
                goal = i;
            }
        }
        if(goal==0){
            return true;
        }
        return false;
    }
};