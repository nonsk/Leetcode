class Solution {
public:
    void solve(int index, int sum, int target, vector<int>& candidates,
               vector<vector<int>>& ans, vector<int>& curr) {
        if (sum > target) {
            return;
        }
        if (index > candidates.size()) {
            return;
        }
        if (index == candidates.size()) {
            if (sum == target) {
                ans.push_back(curr);
                return;
            }
            return;
        }
        if (sum == target) {
            ans.push_back(curr);
            return;
        }

        curr.push_back(candidates[index]);
        solve(index+1, sum + candidates[index], target, candidates, ans, curr);
        curr.pop_back();
        //skip
        int i = index;
        while(i<candidates.size()-1&&candidates[i]==candidates[i+1]){
            i++;
        }
        solve(i+1, sum, target, candidates, ans, curr);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(),candidates.end() );
        solve(0, 0, target, candidates, ans, curr);
        return ans;
    }
};