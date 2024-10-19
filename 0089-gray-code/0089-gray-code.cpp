class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 1) {
            vector<int> ans;
            ans.push_back(0);
            ans.push_back(1);
            return ans;
        }
        vector<int> last = grayCode(n - 1);
        vector<int> last2 = last;
        int m = last.size();
        for(auto it:last2){
            cout<<it<<" ";
        }
        reverse(last2.begin(), last2.end());
        for(int i=0; i<last2.size(); i++){
            last.push_back(last2[i] += m);
        }
        return last;
        
    }
};