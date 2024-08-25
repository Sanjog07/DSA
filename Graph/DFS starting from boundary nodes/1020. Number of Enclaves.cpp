

// Exactly same as 130. Surrounded Regions

class Solution {
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    void dfs(int x,int y,int m,int n, vector<vector<int>>& nums, vector<vector<bool>>& vis){
        vis[x][y] = true;
        nums[x][y] = -1;
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >=0 && ny >=0 && nx < m && ny < n && nums[nx][ny] == 1){
                dfs(nx, ny,m, n,nums,vis);
            }
        }
    }
    
public:
    int numEnclaves(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = nums[0].size();
        
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if((i == 0 || j == 0 || i == m-1 || j == n-1) && nums[i][j] == 1){
                    dfs(i,j,m, n,nums,vis);
                }
            }
        }
        
        // yha if wali condi mei vis[x][y] check krne ki zarurat nhi hai
        // as hum 1 ko -1 mei change kr de rhe hai
        
 
        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(nums[i][j] == 1){
                    cnt++;
                }
            }
        }        
        
        return cnt;
    }
};