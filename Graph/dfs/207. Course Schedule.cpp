

// Possibility of finishing all courses given pre-requisites -> InterviewBit 
// same as this




class Solution {
    
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
    bool canFinish(int nc, vector<vector<int>>& nums) {
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
            if(vis[i] == false && detect_cycle(i, vis, path, adj)){
                return false;
            }
        }
        
        return true;
    }
};




// class Solution {
    
//     bool isCycle(int src,vector<int> adj[],vector<bool> &vis,vector<bool> &path){
//         vis[src] = true;
//         path[src] = true;
        
//         for(auto nbr : adj[src]){
//             if(!vis[nbr]){
//                 if(isCycle(nbr,adj,vis,path)){
//                     return true;
//                 }
//             }else if(path[nbr] == true){
//                 return true;
//             }
//         }
//         //while leaving a node
//         path[src] = false;
//         return false;
//     }
    
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         int n = prerequisites.size();
//         if(n == 0 || n == 1 || numCourses == 1){
//             return true;
//         }
        
//         vector<int> adj[numCourses];
//         for(auto v : prerequisites){
//             adj[v[0]].push_back(v[1]);
//         }
        
//         vector<bool> vis(numCourses);
//         vector<bool> path(numCourses);
        
//         for(int i=0; i<numCourses; i++){
//             vis[i] = path[i] = false;
//         }
        
//         for(int i=0; i<numCourses; i++){
//             if(isCycle(i,adj,vis,path)){
//                 return false;
//             }
//         }
//         return true;
//     }
// };