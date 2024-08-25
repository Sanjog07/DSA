


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


/////////////////////////////////////////////////////////////////////////////////////////////////////////////



// 1-D bottom-up
// jo 1-D mei recursive wala inner loop hota hai -> that fails here

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        int dp[amount+1];
        memset(dp, 0, sizeof(dp));
        
        dp[0] = 1;
        
        // yha pe hume no of combinations nikalni hai
        // no of permutations nhi
        
        for(int i=0; i<n; i++){
            for(int j=coins[i]; j<=amount; j++){
                dp[j] += dp[j - coins[i]];
            }
        }
        
        return dp[amount];
    }
};


class Solution {
    
    
    //NEECHE BOTTOM-UP BHI HAI 
    
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
        
//         dp[n+1][amount+1];
//         memset(dp, -1, sizeof(dp));
        
//         return solve(coins,amount,n);
        

               BOTTOM - UP


        //vector<vector<int>> dp(n+1, vector<int> (amount+1));
        int dp[n+1][amount+1];
        memset(dp, 0, sizeof(dp));
        
        for(int i=0; i<=n; i++){
            for(int j=0; j<=amount; j++){
                if(i == 0){
                    dp[i][j] = 0;
                }
                if(j == 0){
                    dp[i][j] = 1;
                }else if(i != 0 && j != 0){
                    int ans1 = 0, ans2 = 0;
                    if(coins[i-1] <= j){
                        ans1 = dp[i][j-coins[i-1]];
                    }
                    ans2 = dp[i-1][j];

                    dp[i][j] = ans1+ans2;                    
                }

            }
        }
        
        return dp[n][amount];
    }
};