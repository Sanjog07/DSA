class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[n];
        
        dp[0] = 1;
        
        int idx2 = 0, idx3 = 0, idx5 = 0;
        int ans = 0;
        for(int i=1; i<n; i++){
            // dp[i] will tell (i+1)th ugly no

            ans = min({2*dp[idx2], 3*dp[idx3], 5*dp[idx5]});
            dp[i] = ans;
            
            if(ans == 2*dp[idx2]) idx2++;
            if(ans == 3*dp[idx3]) idx3++;
            if(ans == 5*dp[idx5]) idx5++;
        }
        
        return dp[n-1];
        
    }
};