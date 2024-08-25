class Solution {
    
    bool dfs(int node, int des, vector<vector<int>> &adj,vector<bool> &vis){
        vis[node] = true;
        
        for(auto nbr: adj[node]){
            if(nbr == des){
                return true;
            }
            if(!vis[nbr]){
                bool solu = dfs(nbr, des, adj, vis);
                if(solu){
                    return true;
                }
            }
        }
        
        return false;
    }
    
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& que) {
        
        int m = que.size();
        vector<bool> ans(m);
        
        vector<vector<int>> adj(n);
        for(auto v: pre){
            adj[v[0]].push_back(v[1]);
        }
        
        
        for(int i=0; i<m; i++){
            vector<bool> vis(n, false);
            bool res = dfs(que[i][0], que[i][1], adj, vis);
            ans[i] = res;
        }
        
        return ans;
    }
};