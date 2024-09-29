class Solution {
public:
    void solve(int index, int sum, int target, vector<int>& candidates,
               vector<vector<int>>& ans, vector<int> &curr) {
        if (sum > target) {
            return;
        }
        if (index >= candidates.size()) {
            return;
        }
        if (sum == target) {
            ans.push_back(curr);
            return;
        }
        
        curr.push_back(candidates[index]);
        solve(index, sum + candidates[index], target, candidates, ans, curr);
        curr.pop_back();
        solve(index + 1, sum, target, candidates, ans, curr);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0, 0, target, candidates, ans, curr);
        return ans;
    }
};