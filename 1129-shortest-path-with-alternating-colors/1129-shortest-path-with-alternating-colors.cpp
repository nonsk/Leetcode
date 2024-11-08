class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
                                         vector<vector<int>>& blueEdges) {
        vector<vector<int>> redGraph(n), blueGraph(n);

        for (auto& edge : redEdges)
            redGraph[edge[0]].push_back(edge[1]);
        for (auto& edge : blueEdges)
            blueGraph[edge[0]].push_back(edge[1]);

        queue<tuple<int, int, int>> q;

        vector<vector<bool>> visited(n, vector<bool>(2, false));

        vector<int> result(n, -1);
        result[0] = 0;

        q.push({0, 0, 0});
        q.push({0, 1, 0});
        visited[0][0] = visited[0][1] = true;

        while (!q.empty()) {
            auto [node, color, dist] = q.front();
            q.pop();

            if (color == 0) {
                for (int neighbor : blueGraph[node]) {
                    if (!visited[neighbor][1]) {
                        visited[neighbor][1] = true;
                        q.push({neighbor, 1, dist + 1});
                        if (result[neighbor] == -1)
                            result[neighbor] = dist + 1;
                    }
                }
            } else {
                for (int neighbor : redGraph[node]) {
                    if (!visited[neighbor][0]) {
                        visited[neighbor][0] = true;
                        q.push({neighbor, 0, dist + 1});
                        if (result[neighbor] == -1)
                            result[neighbor] = dist + 1;
                    }
                }
            }
        }

        return result;
    }
};