class Solution {
public:
    // int ans(vector<int>& curr, int a){
    //     if(curr.size()<a){
    //         return a;
    //     }
    //     vector<int> temp;
    //     return a;
    // }
    // void solve(){

    // }
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()==1){return 1;}
        if(nums.size()==2){
            return (nums[0]!=nums[1])?2:1;
        }
        vector<int> temp(nums.size(), 0);
        for(int i =1; i<nums.size(); i++){
            temp[i] = nums[i]-nums[i-1];
        }
        int ans = 1;
        if(nums[0]==0){
            ans=0;
        }
        int swtch;
        if(temp[1]<0){
            swtch = -1;
        }
        else {
            swtch = 1;
        }
        for(auto it : temp){
            cout<<it<<" ";
        }
        for(int i =1; i<temp.size(); i++){
            // cout<<swtch<<" ";
            if(swtch==1 && temp[i]<0){
                ans++;
                swtch = -1;
            }
            if(swtch==-1 && temp[i]>0){
                ans++;
                swtch = 1;
            }
        }
        return ans+1;
    }
};