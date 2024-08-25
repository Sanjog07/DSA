class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj){
        int n = adj.size();
        
        vector<int> color(n, -1);
        
        // traversing all the connected components using BFS
        
        for(int i=0; i<n; i++){
            if(color[i] == -1){
                queue<int> q;
                q.push(i);
                color[i] = 1;
                while(!q.empty()){
                    auto node = q.front();
                    q.pop();
                    for(auto nbr: adj[node]){
                        if(color[nbr] == -1){
                            color[nbr] = 1 - color[node]; // color the nbr with opposite color
                            q.push(nbr);
                        }else if(color[nbr] == color[node]){
                            return false;
                        }
                    }
                }                
            }
        }
        
        return true;
    }
};
