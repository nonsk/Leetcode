class NumArray {
public:
    vector<int> yo;
    NumArray(vector<int>& nums) {
        yo = nums;
        yo.push_back(0);
    }
    
    int sumRange(int left, int right) {
        int ans = 0;
        for(int i = left; i<= right; i++){
            ans+=yo[i];
        }
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */