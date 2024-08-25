



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



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        int dp[amount+1];
        for(int i=0; i<=amount; i++){
            dp[i] = INT_MAX - 1;
        }
        
        dp[0] = 0;
        for(int i=0; i<n; i++){
            for(int j=1; j<=amount; j++){
                if(coins[i] <= j){
                    dp[j] = min(dp[j], 1 + dp[j-coins[i]]);
                }
            }
        }
        
        // ye line 14 mei jo if condition lgayi hai uski jagah 
        // hum seedhe j ko coins[i] se start kr skte the
        // but vo tb hota jb given hota ki array sorted hai
        
        return dp[amount] == INT_MAX-1 ? -1 : dp[amount];
    }
};