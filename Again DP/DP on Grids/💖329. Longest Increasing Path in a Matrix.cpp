

int dp[202][202];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

class Solution {
    
    int helper(int x,int y,int m,int n, vector<vector<int>>& nums){
        if(dp[x][y] != -1){
            return dp[x][y];
        }
        
        int res = 1; // yha pe 1 hai 0 nhi bcz agr ek cell se khi nhi ja skte
        // to uska ans 1 hoga na 0 nhi -> kind of base case
        // here see 9 at (0,0)
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && ny >= 0 && nx < m && ny < n && nums[nx][ny] > nums[x][y]){
                int ans = 1 + helper(nx, ny,m, n, nums);
                res = max(res, ans);
            }            
        }
        
        return dp[x][y] = res;
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = nums[0].size();
        
        dp[m+1][n+1];
        memset(dp, -1, sizeof(dp));
        
        int res = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(dp[i][j] == -1){
                    int ans = helper(i, j,m, n, nums);
                    res = max(res, ans);                    
                }
            }
        }
        
        return res;
    }
};