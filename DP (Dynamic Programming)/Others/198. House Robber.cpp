class Solution {
    
    int dp[102];
    int solve(vector<int>& nums,int n,int i){
        if(i >= n){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        
        int a = nums[i] + solve(nums,n,i+2);
        int b = solve(nums,n,i+1);
        
        return dp[i] = max(a,b);
    }
    
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        dp[n];
        memset(dp, -1, sizeof dp);
        
        return solve(nums,n,0);
    }
};


// class Solution {
    
//     int dp[101];
    
//     int helper(int i,int n,vector<int>& nums){
//         if(i >= n){
//             return 0;
//         }
//         if(dp[i] != -1){
//             return dp[i];
//         }
        
//         int ans1 = nums[i] + helper(i+2,n,nums);
//         int ans2 = nums[i] + helper(i+3,n,nums);
        
//         return dp[i] = max(ans1,ans2);
//     }
    
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
        
//         dp[n+1];
//         memset(dp , -1 , sizeof(dp));
//         int op1 = helper(0,n,nums);
//         int op2 = helper(1,n,nums);
        
//         return max(op1,op2);
//     }
// };