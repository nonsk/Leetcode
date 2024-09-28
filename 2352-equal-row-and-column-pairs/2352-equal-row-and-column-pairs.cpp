class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> umap;
        int n = grid.size();
        for (int it = 0; it < n; it++) {
            string s = "";
            for (int i = 0; i < n; i++) {
                s = s + to_string(grid[it][i]);
                s += ",";
            }
            umap[s]++;
        }
        int count = 0;
        for (int j = 0; j < n; j++) {
            string s = "";
            for (int i = 0; i < n; i++) {
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