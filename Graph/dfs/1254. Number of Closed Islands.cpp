
//Explaination in Copy


class Solution {
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
//     bool dfs(int x,int y,vector<vector<int>>& nums,int m,int n){
//         nums[x][y] = -1; // for visited
        
//         for(int i=0; i<4; i++){
//             int nx = x + dx[i];
//             int ny = y + dy[i];
            
//             if(nx >= 0 && ny >= 0 && nx < m && ny < n && nums[nx][ny] == 0){
                
//                 if(!dfs(nx, ny, nums,  m, n)){
//                     return false;
//                 }
//             }else if(nx < 0 || ny < 0 || nx > m || ny > n){
//                 return false;
//             }
//         }
        
//         return true;
//     }
    
    bool flag = true;
    void dfs(int x,int y,vector<vector<int>>& nums,int m,int n){
        nums[x][y] = -1; // for visited
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && ny >= 0 && nx < m && ny < n && nums[nx][ny] == 0){
                
                dfs(nx, ny, nums,  m, n);
            }else if(nx < 0 || ny < 0 || nx >= m || ny >= n){
                flag = false;
            }
        }
        
        return;
    }    
    
public:
    int closedIsland(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = nums[0].size();
        
        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(nums[i][j] == 0){
                    flag = true;
                    dfs(i, j, nums, m, n);
                    if(flag){
                        //cout<<i<<" "<<j<<endl;
                        cnt++;
                    }
                }
            }
        }
        
        return cnt;
    }
};