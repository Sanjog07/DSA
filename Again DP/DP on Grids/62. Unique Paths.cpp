

int mod = 2*1e9 + 1; // hn ye value int mei aa jayegi as INT_MAX = 2147483647

int dp[103][103];

int dx[2] = {0,1}; 
int dy[2] = {1, 0};


class Solution {
    
int helper(int x,int y,int m,int n){
    if(x == m-1 && y == n-1){
        return 1;
    }
    if(dp[x][y] != -1){
        return dp[x][y];
    }

    int res = 0;
    for(int i=0; i<2; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && ny >= 0 && nx < m && ny < n){
            int ans = helper(nx, ny, m, n)%mod;
            res = (res%mod + ans%mod)%mod;
        }
    }

    return dp[x][y] = res%mod;
}    
    
public:
    int uniquePaths(int m, int n) {
        dp[m+1][n+1];
        memset(dp, -1, sizeof(dp));

        return helper(0,0,m, n);   
    }
};




