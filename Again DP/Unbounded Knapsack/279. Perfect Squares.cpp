
// Notebook

    
int dp[10002];

class Solution {

    int helper(int n){
        if(n == 0){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        
        int res = INT_MAX-1;
        for(int i=1; i<=sqrt(n); i++){
            int x = i*i;
            int ans = 1 + helper(n-x);
            res = min(res,ans);
        }
        
        return dp[n] = res;
    }
    
public:
    int numSquares(int n) {
        dp[n+1];
        memset(dp, -1, sizeof(dp));
        
        int res = helper(n);
        
        return (res == INT_MAX-1) ? -1 : res;
    }
};