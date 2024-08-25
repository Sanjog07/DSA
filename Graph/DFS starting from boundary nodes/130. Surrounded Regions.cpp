class Solution {
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};    
    
    void dfs(int x,int y, int m,int n, vector<vector<char>>& nums, vector<vector<bool>> &vis){
        
        vis[x][y] = true;
        nums[x][y] = 'A';
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];  
            
            if(nx >= 0 && ny >= 0 && nx < m && ny < n && nums[nx][ny] == 'O' && vis[nx][ny] == false){
                dfs(nx, ny, m, n, nums, vis);
            }
        }
    }
    
public:
    void solve(vector<vector<char>>& nums) {
        int m = nums.size();
        int n = nums[0].size();
        
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(nums[i][j] == 'O'&&(i == 0 || j == 0 || i == m-1 || j == n-1)){
                    dfs(i,j,m, n,nums, vis);
                }
            }
        }   

        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(nums[i][j] == 'A'){
                    nums[i][j] = 'O';
                }else if(nums[i][j] == 'O'){
                    nums[i][j] = 'X';
                }
            }
        }  
        
        return;
    }
};





// // Explaina

// class Solution {
    
//     int dx[4] = {-1, 0, 1, 0};
//     int dy[4] = {0, 1, 0, -1};   
    
    
//     bool flag = true;
//     void dfs(int x,int y, vector<vector<char>>& nums,int m,int n, vector<vector<bool>> &vis){
        
//         nums[x][y] = 'X';
//         vis[x][y] = true;
        
//         for(int i=0; i<4; i++){
//             int nx = x + dx[i];
//             int ny = y + dy[i]; 
            
//             if(nx >= 0 && ny >= 0 && nx < m && ny < n && nums[nx][ny] == 'O' && vis[nx][ny] == false){
//                 dfs(nx, ny, nums, m, n, vis);
//                 if(flag == false){
                    
//                     // jin nodes se ans false aa rha hai unke visited ko false nhi krna -> vrna firse un nodes se iteration start ho jayegin main()
//                     // as hum un x and y pe nums[x][y] = 'O' firse rkh de rhe hai
                    
//                     nums[x][y] = 'O';
//                 }
//             }else if(nx < 0 || ny < 0 || nx >= m || ny >= n){
//                 // it means ki 'O' border pe hai
//                 flag = false;
//                 nums[x][y] = 'O';
//             }
//         }
        
//         //nums[x][y] = 'O';
//         return;
//     }    
    
// //     bool dfs(int x,int y, vector<vector<char>>& nums,int m,int n, vector<vector<bool>> &vis){
        
// //         nums[x][y] = 'X';
// //         vis[x][y] = true;
        
// //         for(int i=0; i<4; i++){
// //             int nx = x + dx[i];
// //             int ny = y + dy[i]; 
            
// //             if(nx >= 0 && ny >= 0 && nx < m && ny < n && nums[nx][ny] == 'O'){
// //                 bool ans = dfs(nx, ny, nums, m, n, vis);
// //                 if(ans == false){
                    
// //                     // jin nodes se ans false aa rha hai unke visited ko false nhi krna -> vrna firse un nodes se iteration start ho jayegin main()
// //                     // as hum un x and y pe nums[x][y] = 'O' firse rkh de rhe hai
                    
// //                     nums[x][y] = 'O';
// //                     return false;
// //                 }
// //             }else if(nx < 0 || ny < 0 || nx >= m || ny >= n){
// //                 // it means ki 'O' border pe hai
// //                 nums[x][y] = 'O';
// //                 return false;
// //             }
// //         }
        
// //         return true;
// //     }
    
// public:
//     void solve(vector<vector<char>>& nums) {
//         int m = nums.size();
//         int n = nums[0].size();
        
//         vector<vector<bool>> vis(m, vector<bool>(n, false));
        
//         for(int i=0; i<m; i++){
//             for(int j=0; j<n; j++){
//                 if(nums[i][j] == 'O' && vis[i][j] == false){
//                     flag = true;
//                     dfs(i,j, nums, m, n, vis);
//                 }
//             }
//         }
        
//         return;
//     }
// };