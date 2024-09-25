class Solution {
public:
    int candy(vector<int>& ratings) {
        int l = 0;
        int r = 1;
        int count = 0;
        vector<int> ans(ratings.size(), 1);
        for(int i = 0; i<ratings.size()-1; i++){
            if(ratings[i+1]>ratings[i]){
                ans[i+1] = ans[i]+1;
            }
        }
        for(int i = ratings.size()-2; i>=0; i--){
            if(ratings[i]>ratings[i+1]){
                ans[i] = max(ans[i+1]+1, ans[i]);
            }
        }
        for(int i = 0; i<ratings.size(); i++){
            count = ans[i]+count;
        }
        return count;
    }
};