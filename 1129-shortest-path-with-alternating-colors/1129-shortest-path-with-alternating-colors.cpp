class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
         // Graphs for red and blue edges
    vector<vector<int>> redGraph(n), blueGraph(n);
    
    // Populate the graphs
    for (auto& edge : redEdges)
        redGraph[edge[0]].push_back(edge[1]);
    for (auto& edge : blueEdges)
        blueGraph[edge[0]].push_back(edge[1]);
    
    // Result array initialized to -1 (unreachable) for all nodes
    vector<int> result(n, -1);
    result[0] = 0;  // Distance to node 0 is 0
    
    // BFS queue: (node, color) => color: 0 = red, 1 = blue
    queue<pair<int, int>> q;
    q.push({0, 0});  // Start with red
    q.push({0, 1});  // Start with blue
    
    // Distance array: dist[node][color] = minimum distance to node with that color
    vector<vector<int>> dist(n, vector<int>(2, -1));  // -1 means unvisited
    dist[0][0] = dist[0][1] = 0;  // Starting node 0 has distance 0 with both colors
    
    // BFS loop
    while (!q.empty()) {
        auto [node, color] = q.front();
        q.pop();
        
        int currentDist = dist[node][color];
        
        // Determine which graph to use based on the last edge color
        const vector<int>& nextEdges = (color == 0) ? blueGraph[node] : redGraph[node];
        int nextColor = 1 - color;  // Toggle the color
        
        // Explore neighbors
        for (int neighbor : nextEdges) {
            if (dist[neighbor][nextColor] == -1) {  // Not visited with this color yet
                dist[neighbor][nextColor] = currentDist + 1;
                q.push({neighbor, nextColor});
                
                // Update result if this is the first shortest path found
                if (result[neighbor] == -1) {
                    result[neighbor] = currentDist + 1;
                }
            }
        }
    }
    
    return result;
    }
};