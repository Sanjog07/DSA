class Solution {
    
    void dfs(int node,vector<vector<int>>& nums, vector<bool> &vis){
        vis[node] = true;
        
        for(auto nbr: nums[node]){
            if(!vis[nbr]){
                dfs(nbr, nums, vis);
            }
        }
    }
    
public:
    bool canVisitAllRooms(vector<vector<int>>& nums) {
        int n = nums.size();
        
        vector<bool> vis(n, false);
        
        dfs(0, nums, vis);
        
        for(int i=0; i<n; i++){
            if(vis[i] == false){
                return false;
            }
        }
        
        return true;
    }
};