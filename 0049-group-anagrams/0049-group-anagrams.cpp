class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<int>> umap;
        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            umap[s].push_back(i);
        }
        vector<vector<string>> ans;
        for (auto it : umap) {
            vector<string> variable;
            for (auto it2 : it.second) {
                variable.push_back(strs[it2]);
            }
            ans.push_back(variable);
        }
        return ans;
    }
};