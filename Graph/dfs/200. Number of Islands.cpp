class Solution {
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    void dfs(int x,int y,vector<vector<char>>& nums,int m,int n){
        nums[x][y] = 'a'; // for visited
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && ny >= 0 && nx < m && ny < n && nums[nx][ny] == '1'){
                
                dfs(nx, ny, nums,  m, n);
            }
        }
        
        return;
    }
    
public:
    int numIslands(vector<vector<char>>& nums) {
        int m = nums.size();
        int n = nums[0].size();
        
        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(nums[i][j] == '1'){
                    dfs(i, j, nums, m, n);
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};





// class Solution{
    
//     int dx[4] = {-1,0,1,0};
//     int dy[4] = {0,1,0,-1};
    
//     void dfs(int x ,int y, vector<vector<bool>> &vis,vector<vector<char>> &grid,int n,int m){
//         if(x < 0 || y  < 0 || x >= n || y >= m){
//             return;
//         }        
//         if(grid[x][y] == '0'){
//             return;
//         }
        
//         if(!vis[x][y]){
//             vis[x][y] = true;
            
//             for(int i=0; i<4; i++){
//                 int nx = x+dx[i];
//                 int ny = y+dy[i];
                
//                 dfs(nx,ny,vis,grid,n,m);
//             }            
//         }
        
//         return;
//     }
//     public:
//     //Function to find the number of islands.
//     int numIslands(vector<vector<char>>& grid){
//         int n = grid.size();
//         int m = grid[0].size();
        
        
//         vector<vector<bool>> vis(n , vector<bool> (m, false));
        
//         int cnt = 0;
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(!vis[i][j] && grid[i][j] == '1'){
//                     dfs(i,j,vis,grid,n,m);
//                     cnt++;
//                 }
//             }
//         }
//         return cnt;
//     } 
// };