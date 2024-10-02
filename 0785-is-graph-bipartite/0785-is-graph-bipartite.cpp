class Solution {
public:
    bool fill(unordered_set<int>& A, unordered_set<int>& B, vector<char>& vis,
              int test, char yo, vector<vector<int>>& graph) {
        vis[test] = yo;
        for (int i = 0; i < vis.size(); i++) {
            if (vis[i] == 'B') {
                for (auto it : graph[i]) {
                    {
                        if (vis[it] == 'B') {
                            return false;
                        }
                        vis[it] = 'A';
                    }
                }
            }
            if (vis[i] == 'A') {
                vis[i] = 'A';
                for (auto it : graph[i]) {
                    {
                        if (vis[it] == 'A') {
                            return false;
                        }
                        vis[it] = 'B';
                    }
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_set<int> A;
        unordered_set<int> B;
        vector<char> vis(graph.size(), -1);
        bool ans = false;
        for (int i = 0; i < vis.size(); i++) {
            if (1) {
                ans = fill(A, B, vis, i, 'A', graph) ||
                      fill(A, B, vis, i, 'B', graph);
            }
        }
        return ans;
    }
};