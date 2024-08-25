
      int fun(){
        
        int dp[n+1][tar+1];
        memset(dp, -1, sizeof(dp));  
        
        for(int i=0; i<=n; i++){
            for(int j=0; j<=sum; j++){
                if(i == 0){
                    dp[i][j] = 0;
                }
                if(j == 0){
                    dp[i][j] = 1;
                }else if(i != 0 && j != 0){
                    
                    int ans1 = 0, ans2 = 0;
                    if(nums[i-1] <= j){
                        ans1 = dp[i-1][j-nums[i-1]];
                    }
                    ans2 = dp[i-1][j];
                    
                    dp[i][j] = ans1 + ans2;
                }
            }
        }
        
        return dp[n][sum];

      }