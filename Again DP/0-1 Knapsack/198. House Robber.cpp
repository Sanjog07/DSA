
// simple sochna hai niche ki tarah knapsack ki bhi zarurat nhi hai

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



int dp[103][103];

//dp[n][last+1] -> yha pe last+1 isliye kiya bcz starting mei last = -1 
// le ke chal rhe hai, so out if bound na chala jaye isliye

class Solution {
    
    int helper(int n, int last, vector<int>& nums){
        if(n == 0){
            return 0;
        }
        if(dp[n][last+1] != -1){
            return dp[n][last+1];
        }
        
        int ans1 = 0, ans2 = 0;
        if(last == -1 || ((n-1) < (last - 1))){
            ans1 = nums[n-1] + helper(n-1, n-1, nums);
        }
        
        ans2 = helper(n-1, last, nums);
        
        return dp[n][last+1] = max(ans1, ans2);
    }
    
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        dp[n+1][n+1];
        memset(dp, -1, sizeof(dp));
        
        int res = helper(n, -1, nums);
        
        return res;
    }
};