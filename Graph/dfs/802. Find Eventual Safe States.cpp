

// https://www.youtube.com/watch?v=4ymVOCiQBtw

class Solution {
    
    bool detect_cycle(int src, vector<bool> &vis,vector<bool> &path,vector<bool> &ans, vector<vector<int>> &adj){
        vis[src] = true;
        path[src] = true;
        
        for(auto nbr: adj[src]){
            if(vis[nbr] == true && path[nbr] == true){
                return ans[src] = true;
            }else if(vis[nbr] == false){                
                bool hasCycle = detect_cycle(nbr, vis ,path, ans, adj);
                if(hasCycle){
                    return ans[src] = true;
                }
            }
        }
        
        path[src] = false;
        
        return ans[src] = false;
    }
    
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& nums) {
        // agr ek node loop/cycle mei nhi fass rhi then 
        // it is a safe node
        
        int n = nums.size();
        
        vector<bool> vis(n, false);
        vector<bool> path(n, false);
        vector<bool> ans(n, false);
        // ans[i] == true -> means ye node kisi ek cycle ka part hai
        
        for(int i=0; i<n; i++){
            if(!vis[i]){
                detect_cycle(i, vis, path, ans, nums);
            }
        }
        
        vector<int> solu;
        for(int i=0; i<n; i++){
            if(!ans[i]){
                solu.push_back(i);
            }
        }
        
        return solu;
    }
};