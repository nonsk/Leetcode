class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> umap;
        int n = grid.size();
        for (auto it: grid) {
            umap[it]++;
        }

        int count = 0;
        for (int j = 0; j < n; j++) {
            vector<int> temp;
            for (int i = 0; i < n; i++) {
                temp.push_back(grid[i][j]);
            }
            if(umap.find(temp)!=umap.end()){
                count = count + umap[temp];
            }
        }
        return count;
    }
};