class Solution {
    
    vector<int> ans;
    void topo_sort(int node, vector<bool> &vis, vector<vector<int>> &adj){
        vis[node] = true;
        
        for(auto nbr: adj[node]){
            if(!vis[nbr]){
                topo_sort(nbr, vis, adj);
            }
        }
        
        ans.insert(ans.begin(), node);
        return;
    }
    
    bool detect_cycle(int src, vector<bool> &vis,vector<bool> &path, vector<vector<int>> &adj){
        vis[src] = true;
        path[src] = true;
        
        for(auto nbr: adj[src]){
            if(vis[nbr] == true && path[nbr] == true){
                return true;
            }else if(vis[nbr] == false){                
                bool hasCycle = detect_cycle(nbr, vis ,path, adj);
                if(hasCycle){
                    return true;
                }
            }
        }
        
        path[src] = false;
        
        return false;
    }    
    
public:
    vector<int> findOrder(int nc, vector<vector<int>>& nums) {
        int n = nums.size();

        vector<vector<int>> adj(nc, vector<int>());
        
        for(auto vec: nums){
            adj[vec[1]].push_back(vec[0]);
        }
        
        vector<bool> vis(nc, false);
        vector<bool> path(nc, false);
        
        
        // there can be more than 1 connected components
        // 20
        // [[0,10],[3,18],[5,5],[6,11],[11,14],[13,1],[15,1],[17,4]]
        for(int i=0; i<nc; i++){
            if(detect_cycle(i, vis, path, adj)){
                return {};
            }
        }
        
        for(int i=0; i<nc; i++){
            vis[i] = false;
        } 
        
        for(int i=0; i<nc; i++){
            if(vis[i] == false){
                topo_sort(i, vis, adj);
            }
        }
        
        return ans;
               
    }
};