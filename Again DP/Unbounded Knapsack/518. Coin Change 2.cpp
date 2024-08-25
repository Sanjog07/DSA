
class Solution {
    
    
    // NEECHE BOTTOM-UP BHI HAI 
    
    int dp[302][5002];
    
    int solve(vector<int>& coins,int amount,int n){
        if(amount == 0){
            return 1;
        }
        if(n == 0){
            return 0;
        }
        if(dp[n][amount] != -1){
            return dp[n][amount];
        }
        
        int ans1 = 0, ans2 = 0;
        if(coins[n-1] <= amount){
            ans1 = solve(coins,(amount-coins[n-1]),n);
        }
        ans2 = solve(coins,amount,n-1);
        
        return dp[n][amount] = ans1+ans2;
    }
    
public:
    int change(int amount, vector<int>& coins) {

        int n = coins.size();
        
        dp[n+1][amount+1];
        memset(dp, -1, sizeof(dp));
        
        return solve(coins,amount,n);
    }
};