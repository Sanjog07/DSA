
bool isSafe(int node, int col, bool graph[101][101],int n, vector<int> &color){
    
    for(int j=0; j<n; j++){
        if(j != node && graph[node][j] == 1 && color[j] == col){
            return false;
        }
    }
    
    return true;
}

bool dfs(int node, bool graph[101][101], int m, int n, vector<int> &color){
    if(node == n){
        return true;
    }
    
    for(int i=1; i<=m; i++){
        if(isSafe(node,i,graph, n, color)){
            color[node] = i;
            bool ans = dfs(node+1, graph, m, n, color);
            if(ans){
                return true;
            }
            color[node] = 0;        
        }
    }
    
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    vector<int> color(n, 0);

    bool ans = dfs(0, graph, m, n, color);
    
    return ans;
}