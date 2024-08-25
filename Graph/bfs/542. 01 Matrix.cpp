
// iss wale mei galti ye aa rhi thhi ki hum sirf first wale 0 ko
// queue mei daal rhe thhe
// so instead of inserting just the first 0, insert all the 0's
// in the queue in the very starting
// correct wala code niche hai

// class custom{
//     public:
    
//     int x;
//     int y;
//     int d;
// };

// class Solution {
    
//     int dx[4] = {-1, 0, 1, 0};
//     int dy[4] = {0, 1, 0, -1};
    
// public:
//     vector<vector<int>> updateMatrix(vector<vector<int>>& nums) {
//         int m = nums.size();
//         int n = nums[0].size();
        
//         vector<vector<int>> ans(m, vector<int>(n, -1));
//         vector<vector<int>> vis(m, vector<int>(n, 0));
        
//         queue<custom> q;
//         for(int i=0; i<m; i++){
//             for(int j=0; j<n; j++){
//                 if(nums[i][j] == 0){
//                     q.push({i, j, 0});
//                     ans[i][j] = 0;
//                     vis[i][j] = 1;
//                     break;
//                 }
//             }
//         }
        
        
//         while(!q.empty()){
//             auto f = q.front();
//             q.pop();
            
//             int dist = f.d;
            
//             for(int i=0; i<4; i++){
//                 int nx = f.x + dx[i];
//                 int ny = f.y + dy[i];
                
//                 if(nx >= 0 && ny >= 0 && nx < m && ny < n&&vis[nx][ny] == 0){
//                     if(nums[nx][ny] == 0){
//                         q.push({nx, ny, 0});
//                         ans[nx][ny] = 0;
//                     }else{
//                         q.push({nx, ny, dist + 1});
//                         ans[nx][ny] = dist + 1;
//                     }
                    
//                     vis[nx][ny] = 1;
//                 }
//             }
//         }
        
//         return ans;
//     }
// };




class custom{
    public:
    
    int x;
    int y;
    int d;
};

class Solution {
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = nums[0].size();
        
        vector<vector<int>> ans(m, vector<int>(n, -1));
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        queue<custom> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(nums[i][j] == 0){
                    q.push({i, j, 0});
                    ans[i][j] = 0;
                    vis[i][j] = 1;
                }
            }
        }
        
        
        while(!q.empty()){
            auto f = q.front();
            q.pop();
            
            int dist = f.d;
            
            for(int i=0; i<4; i++){
                int nx = f.x + dx[i];
                int ny = f.y + dy[i];
                
                if(nx >= 0 && ny >= 0 && nx < m && ny < n&&vis[nx][ny] == 0){
                    q.push({nx, ny, dist + 1});
                    ans[nx][ny] = dist + 1;                    
                    vis[nx][ny] = 1;
                }
            }
        }
        
        return ans;
    }
};