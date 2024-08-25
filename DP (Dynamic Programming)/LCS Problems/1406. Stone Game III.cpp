

// https://www.youtube.com/watch?v=HsY3jFyaePU


class Solution {
    
    int dp[50001];
    int solve(vector<int>& nums, int n, int i){
        if(i >= n){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        
        int solu = INT_MIN;
        int ans = 0;
        for(int j=i; j<=i+2; j++){
            if(j < n){
                ans += nums[j];
                int val = ans - solve(nums,n,j+1);
                solu = max(solu, val);
            }
        }
        
        return dp[i] = solu;
    }
    
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        dp[n];
        memset(dp, -1, sizeof(dp));
        
        int val = solve(stoneValue,n,0);
        int total = 0;
        total = accumulate(stoneValue.begin(), stoneValue.end(),total);
        
        int alice = (val+total)/2;
        int bob = total - alice;
        
        string ans = "";
        if(alice > bob){
            ans = "Alice";
        }else if(bob > alice){
            ans = "Bob";
        }else{
            ans = "Tie";
        }
        
        return ans;
    }
};