class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        int r = nums.size()-1;

        for(int i =nums.size()-1; i>=0; i--){
            if(nums[i]==val){
                count++;
                int temp;
                temp = nums[i];
                nums[i] = nums[r];
                nums[r] = temp;
                r--;
            }
        }
        return nums.size()-count;
    }
};