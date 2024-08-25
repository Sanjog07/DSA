
class Solution {
    
    int dp[302][10002];
    
    int solve(vector<int>& coins,int amount,int n){
        if(amount == 0){
            return 0;
        }
        if(n == 0){
            return INT_MAX-1;
        }
        if(dp[n][amount] != -1){
            return dp[n][amount];
        }
        
        int ans1 = INT_MAX-1, ans2 = INT_MAX-1;
        if(coins[n-1] <= amount){
            ans1 = 1 + solve(coins,(amount-coins[n-1]),n);
        }
        ans2 = solve(coins,amount,n-1);
        
        return dp[n][amount] = min(ans1,ans2);
    }
    
public:
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        
        dp[n+1][amount+1];
        memset(dp, -1, sizeof(dp));
        
        int solu = solve(coins,amount,n);
        
        return (solu == INT_MAX-1) ? -1 : solu;
    } 
};