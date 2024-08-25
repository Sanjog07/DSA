

// https://leetcode.com/problems/jump-game/discuss/1713802/C%2B%2B-solution-Easiest-approach-O(n)-time-and-O(1)-space

// the above solu is O(n) -> so dekh lena

class Solution {
    
    int dp[10002];
    int solve(vector<int>& nums,int n,int i){
        if(i >= n){
            return 0;
        }
        if(i == n-1){
            return 1;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        
        int ans = 0;
        for(int jump=1; jump<=nums[i]; jump++){
            ans = ans | solve(nums,n,i+jump);
            if(ans){
                return dp[i] = ans;
            }
        }
        
        return dp[i] = ans;
    }
    
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        dp[n];
        memset(dp, -1 , sizeof dp);
        
        return solve(nums,n,0);
    }
};