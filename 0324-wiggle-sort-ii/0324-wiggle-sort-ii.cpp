class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> asc(nums);
        sort(asc.begin(), asc.end());
        int mid = (n - 1) / 2;
        int end = n - 1;       
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                ans[i] = asc[mid--]; 
            } else {
                ans[i] = asc[end--];
            }
        }
        for(int i = 0; i < n; i++){
            nums[i] = ans[i];
        }
    }
};
