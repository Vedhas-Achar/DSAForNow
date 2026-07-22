class Solution {
public:
    
    bool dfs(int node, vector<vector<int>>& isConnected, vector<int>& vis){
        vis[node] = 1;
        for(int i = 0; i < isConnected.size(); i++){
            if(!vis[i] && isConnected[node][i] == 1){
                if(dfs(i, isConnected, vis)) return true;
            }
        }
        return false;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> vis(isConnected.size(), 0);
        int ans = 0;

        for(int i = 0; i < isConnected.size(); i++){
            if(!vis[i]){
                ans++;
                dfs(i, isConnected, vis);
            }
        }
        return ans;
    }
};