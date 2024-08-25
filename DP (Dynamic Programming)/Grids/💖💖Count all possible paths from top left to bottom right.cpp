
// this backtracking method is giving TLE so use DP

#define ll long long int 
int mod = 1e9 + 7;
class Solution {
    
bool isSafe(int x,int y, int m,int n){
    if(x >= 0 && x < m && y >= 0 && y < n){
        return true;
    }
    return false;
}

ll cnt = 0;
void solve(int i, int j, int m, int n){
    if(i == m-1 && j == n-1){
        cnt = (cnt + 1)%mod;
        return;
    }

    int ni = i;
    int nj = j+1;
    if(isSafe(ni, nj, m, n)){
        solve(ni, nj,m, n);
    }

    ni = i+1;
    nj = j;
    if(isSafe(ni, nj, m, n)){
        solve(ni, nj,m, n);
    }

    return;

}    
    
    
  public:
    long long int numberOfPaths(int m, int n){
        solve(0, 0, m, n);
        
        return cnt%mod;
    }
};



//i.e hume basically total no of ways hi nikalne hai
// i.etotal no of ways to reach from start to end


long long int mod = 1e9+7;
class Solution {
    
    int dp[101][101];
    
    bool isSafe(int x,int y,int m,int n){
        if(x >= 0 && x < m && y >=0 && y < n){
            return true;
        }
        return false;
    }
    
    // int dx[2] = {0 , 1};
    // int dy[2] = {1 , 0};    
    
    long long int helper(int i,int j,int m,int n){
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(i >= m || j >= n){
            return 0;
        }        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        long long int ans = 0;
        // for(int i=0; i<2; i++){
        //     int nx = i + dx[i];
        //     int ny = j + dy[i];
        //     if(isSafe(nx,ny,m,n)){
        //         ans = ((ans%mod) + (helper(nx,ny,m,n)%mod))%mod;
        //     }
        // }
        
        long long int right = helper(i,j+1,m,n)%mod;
        long long int down = helper(i+1,j,m,n)%mod;
        
        ans = right+down;
        
        return dp[i][j] = ans%mod;
    }    
    
  public:
    long long int numberOfPaths(int m, int n){
        dp[m][n];
        memset(dp , -1 , sizeof(dp));        
        
        return helper(0,0,m,n);
    }
};