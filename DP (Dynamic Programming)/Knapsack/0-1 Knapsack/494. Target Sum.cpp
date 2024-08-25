class Solution {
    
    int subsetSumToTarget(vector<int>& nums,int n, int tar){
        int dp[n+1][tar+1];
        //memset(dp, 0, sizeof(dp));
        
        for(int i=0; i<=n; i++){
            for(int j=0; j<=tar; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                }else if(i == 0){
                    dp[i][j] = 0;
                }else{
                    int ans1 = 0, ans2 = 0;
                    if(nums[i-1] <= j){
                        ans1 = dp[i-1][j-nums[i-1]];
                    }
                    ans2 = dp[i-1][j];
                    
                    dp[i][j] = ans1+ans2;
                }
            }
        }
        
        return dp[n][tar];
    }
    
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        int sum = 0;
        sum = accumulate(nums.begin(), nums.end(), sum);
        
        int x = sum-target;
        if(abs(target) > sum || x%2 != 0){
            return 0;
        }
        int tar = x/2;
        
        // int cnt = 0;
        // for(int i=0; i<n; i++){
        //     if(nums[i] == 0){
        //         cnt++;
        //     }
        // }
        
        int ans =  subsetSumToTarget(nums,n,tar);
        
        return ans;//*pow(2,cnt);
    }
};