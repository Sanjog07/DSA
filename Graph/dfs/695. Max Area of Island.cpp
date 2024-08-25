class Solution {
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};    
    
    int dfs(int x,int y,vector<vector<int>>& nums,int m,int n){
        nums[x][y] = -1; // for visited
        
        int cnt = 0;
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && ny >= 0 && nx < m && ny < n && nums[nx][ny] == 1){
                cnt += dfs(nx, ny, nums,  m, n);
            }
        }
        
        return cnt+1;        
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = nums[0].size();
        
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(nums[i][j] == 1){
                    int val = dfs(i, j, nums, m, n);
                    ans = max(ans, val);
                }
            }
        }
        
        return ans;
    }        
};