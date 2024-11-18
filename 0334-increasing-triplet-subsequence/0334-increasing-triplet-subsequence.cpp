class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
      int minimum = INT_MAX;
      int s_minimum = INT_MAX;
      for(int i =0; i<nums.size(); i++){
        if(nums[i]<s_minimum){
            if(nums[i]<minimum){
                minimum = nums[i];
                s_minimum = nums[i];
            }
            else {
                s_minimum = nums[i];
            }
        }
        else{
            return true;
        }
      }
      return false;
    }
};