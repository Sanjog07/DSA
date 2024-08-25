

// https://www.youtube.com/watch?v=bLGZhJlt4y0&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=18

class Solution{
    
    vector<string> res;
    
    bool isSafe(int x, int y, vector<vector<int>> &mat, int n, vector<vector<int>> &vis){
        if(x >= 0 && y >= 0 && x < n && y < n && mat[x][y] == 1 && vis[x][y] == 0) {
            return true;
        }
        return false;
    }
    
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, -1, 1, 0};
    
    string str = "DLRU";
    void helper(vector<vector<int>> &mat, int i,int j,string ans,int n, vector<vector<int>> &vis){
        if(i == n-1 && j == n-1){
            res.push_back(ans);
            return;
        }
        
        for(int k=0; k<4; k++){
            int newi =  i + dx[k];
            int newj = j + dy[k];
            
            if(isSafe(newi,newj,mat,n,vis)){
                ans += str[k];
                vis[i][j] = 1;
                helper(mat, newi, newj, ans,n, vis);
                vis[i][j] = 0;
                ans.pop_back();
            }
        }
        
        return;
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &mat, int n) {
        if(mat[0][0] == 0 || mat[n-1][n-1] == 0){
            return {};
        }
        
        vector<vector<int>> vis(n, vector<int> (n, 0));
        
        helper(mat, 0, 0, "", n, vis);
        
        return res;
        
    }
};