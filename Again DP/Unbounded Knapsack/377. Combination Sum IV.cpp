

// Notebook

class Solution {  
    int dp[1002];
    
    int solve(vector<int>& nums,int tar,int n){
        if(tar == 0){
            return 1;
        }
        if(dp[tar] != -1){
            return dp[tar];
        }
        
        int res = 0;
        for(int i=0; i<n; i++){
            if((tar - nums[i]) >= 0){
                int ans = solve(nums, (tar - nums[i]), n);
                res += ans;
            }
        }
        
        return dp[tar] = res;
    }    
    
public:
    int combinationSum4(vector<int>& nums, int tar) {

        int n = nums.size();
        
        dp[tar+1];
        memset(dp, -1, sizeof(dp));
        
        return solve(nums,tar,n);
    }
};