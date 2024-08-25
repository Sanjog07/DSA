class Solution {
    
    int dp[502][502];
    int solve(string s, string t, int n, int m){
        if(n < 0){
            // this much insertions
            return m+1;
        }
        if(m < 0){
            // this much deletions
            return n+1;
        }
        if(dp[n][m] != -1){
            return dp[n][m];
        }
        
        int ans = 0;
        int ans1 = 0, ans2 = 0, ans3 = 0;
        
        if(s[n] == t[m]){
            ans = solve(s,t,n-1,m-1);
        }else{
            
            // as mujhe nhi pta ki konsa operation lgana hai
            // to sabhi operations lga ke dekh lo
            
            ans1 = 1 + solve(s,t,n,m-1); // insertion
            ans2 = 1 + solve(s,t,n-1,m-1); // replace
            ans3 = 1 + solve(s,t,n-1,m); //delete
            
            ans = min({ans1, ans2, ans3});
        }
        
        return dp[n][m] = ans;
    }
    
public:
    int minDistance(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        dp[n][m];
        memset(dp, -1, sizeof dp);
        
        return solve(s,t,n-1,m-1);
    }
};