class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> umap;

        for (auto it : grid) {
            string s = "";
            for (int i = 0; i < it.size(); i++) {
                s = s + to_string(it[i]);
                s += ",";
            }
            umap[s]++;
        }
        int count = 0;
        for (int j = 0; j < grid.size(); j++) {
            string s = "";
            for (int i = 0; i < grid[0].size(); i++) {
                s = s + to_string(grid[i][j]);
                s += ",";
            }
            if(umap.find(s)!=umap.end()){
                count = count + umap[s];
            }
        }
        return count;
    }
};