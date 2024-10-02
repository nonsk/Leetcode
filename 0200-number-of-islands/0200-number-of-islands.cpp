class Solution {
public:
    void do_the_thing(int i, int j, vector<vector<char>>& grid,
                      vector<vector<int>>& visited, int count) {
            int n = grid.size();
    int m = grid[0].size();
        visited[i][j] = count;
cout<<i<<","<<j<<endl;
        if (i != 0 && grid[i - 1][j] == '1'&& visited[i-1][j]==-1) {
            do_the_thing(i - 1, j, grid, visited, count);
        }
        if (j != 0 && grid[i][j - 1] == '1'&& visited[i][j-1]==-1) {
            do_the_thing(i, j - 1, grid, visited, count);
        }
        if (i != n - 1 && grid[i + 1][j] == '1'&& visited[i+1][j]==-1) {
            do_the_thing(i + 1, j, grid, visited, count);
        }
        if (j != m - 1 && grid[i][j + 1] == '1'&& visited[i][j+1]==-1) {
            do_the_thing(i, j + 1, grid, visited, count);
        }
        return;
    }
 int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n + 1, vector<int>(m + 1, -1));
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '1' && visited[i][j] == -1) {
                do_the_thing(i,j,grid, visited, count + 1);
                count++;
            }
        }
    }
    return count;
}
}
;