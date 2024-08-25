

//     // IF THE TOTAL NO OF EDGES WILL BE LESS THAN (TOTAL NO OF VERTICES-1) THEN IT IS IMPOSSIBLE TO DO SO
        
//         // BCZ IN A GRAPH MIN NO OF EDGES CAN BE NO OF VERTICES-1
//         // USSE JYADA CHALENGI USSE KM NHI

//         //AND ANS WILL BE (TOTAL NO OF CONNECTED COMPONENTS - 1) -> 
//         // BCZ FINALLY HUMKO EK CONNECTED COMPONENT BNANA HAI

class Solution{
    
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
    int makeConnected(int n, vector<vector<int>>& nums) {
        int e = nums.size();
        
        if(e < (n-1)){
            return -1;
        }
        
        init(n);
        for(auto v: nums){
            Union(v[0], v[1]);
        }
        
        // unordered_set<int> s;
        // for(int i=0; i<n; i++){
            
        //     // 5  & [[0,1],[0,2],[3,4],[2,3]]
        //     // see this eg why int x = parent[i] kyu nhi aaya
        //     int x = findPar(i);
        //     s.insert(x);
        // }

        int cnt = 0;
        for(int i=0; i<n; i++){
            if(parent[i] == i){
                cnt++;
            }
        }        
        
        return cnt - 1;
    }
};






// class Solution {
    
//     bool vis[100001];
    
//     void dfs_helper(int node,vector<int> adj[]){
//         vis[node] = true;
        
//         for(auto nbr : adj[node]){
//             if(!vis[nbr]){
//                 dfs_helper(nbr,adj);
//             }
//         }
//     }
    
//     int dfs(vector<int> adj[],int n){
//         int cnt = 0;
//         for(int i=0; i<n; i++){
//             vis[i] = false;
//         }
        
//         for(int i=0; i<n; i++){
//             if(!vis[i]){
//                 dfs_helper(i,adj);
//                 cnt++;
//             }
//         }
        
//         return cnt;
//     }
    
// public:
//     int makeConnected(int n, vector<vector<int>>& connections) {
//     // IF THE TOTAL NO OF EDGES WILL BE LESS THAN (TOTAL NO OF VERTICES-1) THEN IT IS IMPOSSIBLE TO DO SO
        
//         // BCZ IN A GRAPH MIN NO OF EDGES CAN BE NO OF VERTICES-1
//         // USSE JYADA CHALENGI USSE KM NHI
        
//         int e = connections.size(); // no of edges
//         if(e < (n-1)){
//             return -1;
//         }
//         //AND ANS WILL BE (TOTAL NO OF CONNECTED COMPONENTS - 1) -> 
//         // BCZ FINALLY HUMKO EK CONNECTED COMPONENT BNANA HAI
        
//         vector<int> adj[n];
//         for(auto v : connections){
            
//             //as it is a undirected graph
//             adj[v[0]].push_back(v[1]);
//             adj[v[1]].push_back(v[0]);
//         }
        
//         return dfs(adj , n) - 1;
//     }
// };