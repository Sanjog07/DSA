class Solution {
public:
    int lastStoneWeightII(vector<int>& nums) {
        int n = nums.size();
        
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
            
        int dp[n+1][sum+1];
        memset(dp, 0, sizeof(dp));
        
        for(int i=0; i<=n; i++){
            for(int j=0; j<=sum; j++){
                if(i == 0){
                    dp[i][j] = 0;
                }
                if(j == 0){
                    dp[i][j] = 1;
                }
                if(i != 0 && j != 0){
                    int ans1 = 0, ans2 = 0;
                    if(nums[i-1] <= j){
                        ans1 = dp[i-1][j-nums[i-1]];
                    }
                    ans2 = dp[i-1][j];
                    
                    dp[i][j] = ans1 || ans2;
                }
            }
        }
                
        
        int mval; 
        for(int j=sum/2; j>=0; j--){
            if(dp[n][j] == true){
                mval = j;
                break;
            }
        }
        
        //cout<<mval;
        
        return sum - 2*mval;
    }
};