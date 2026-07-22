class Solution {
public:

    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;
        
        if(grid[i][j] == '0' || vis[i][j]) return;

        vis[i][j] = 1;
        dfs(i+1, j, grid, vis);
        dfs(i, j+1, grid, vis);
        dfs(i-1, j, grid, vis);
        dfs(i, j-1, grid, vis);
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        int ans = 0;
        for(int i = 0; i < vis.size(); i++){
            for(int j = 0; j < vis[0].size(); j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    ans++;
                    dfs(i, j, grid, vis);
                }
            }
        }
        return ans;
    }
};