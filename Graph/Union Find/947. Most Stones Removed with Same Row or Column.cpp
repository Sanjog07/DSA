

// DFS -> GIVING TLE


// see notebook
class Solution {
    
    vector<int> parent;
    vector<int> rank;
    
    void init(int n){
        parent.resize(n);
        rank.resize(n);
        
        for(int i=0; i<n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    int findPar(int node){
        if(parent[node] == node){
            return node;
        }
        
        return parent[node] = findPar(parent[node]);
    }
    
    void Union(int x, int y){
        int parx = findPar(x);
        int pary = findPar(y);
        
        if(parx != pary){
            if(rank[parx] < rank[pary]){
                parent[parx] = pary; 
            }else if(rank[pary] < rank[parx]){
                parent[pary] = parx; 
            }else{
                parent[pary] = parx;
                rank[parx]++;
            }   
        }
    }    
    
public:
    int removeStones(vector<vector<int>>& nums) {
        int n = nums.size();
        // undirected graph bnega
        
        init(n);
        
        for(int i=0; i<n; i++){
            
            int x = nums[i][0];
            int y = nums[i][1];  
            
            for(int j=i+1; j<n; j++){
                // vector<int> a = nums[i];
                // vector<int> b = nums[j];
                
                int r = nums[j][0];
                int s = nums[j][1];
                
                // if(a[0] == b[0] || a[1] == b[1]){
                //     // i.e they share same row or same col
                //     Union(i, j);
                // }
                if(x == r || y == s){
                    Union(i, j);
                }
            }
        }
        
        // unordered_set<int> s;
        // for(int i=0; i<n; i++){
        //     int x = findPar(i);
        //     s.insert(x);
        // }  
        
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(parent[i] == i){
                cnt++;
            }
        }
        
        return n - cnt;
    }
};





// class Solution {
    
//     void dfs(int node, vector<vector<int>>& adj, vector<bool> &vis){
//         vis[node] = true;
        
//         for(auto nbr: adj[node]){
//             if(!vis[nbr]){
//                 dfs(nbr, adj, vis);
//             }
//         }
        
//         return;
//     }
    
// public:
//     int removeStones(vector<vector<int>>& nums) {
//         int n = nums.size();
//         vector<vector<int>> adj(n);
//         // undirected graph bnega
        
//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 vector<int> a = nums[i];
//                 vector<int> b = nums[j];
                
//                 if(a[0] == b[0] || a[1] == b[1]){
//                     // i.e they share same row or same col
//                     adj[i].push_back(j);
//                     adj[j].push_back(i);
//                 }
//             }
//         }
        
//         vector<bool> vis(n, false);
        
//         int cnt = 0;
//         for(int i=0; i<n; i++){
//             if(!vis[i]){
//                 dfs(i, adj, vis);
//                 cnt++;
//             }
//         }
        
//         return n - cnt;
//     }
// };