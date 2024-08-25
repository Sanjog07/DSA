class Solution {
    
    int lcs(string s,string t,int n ,int m){
        int dp[n+1][m+1];
        memset(dp, -1, sizeof dp);
        
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }else{
                   if(s[i-1] == t[j-1]){
                       dp[i][j] = 1 + dp[i-1][j-1];
                   }else{
                       dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                   }
                } 
            }
        }
        
        return dp[n][m];
    }
    
public:
    int minDistance(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        int len = lcs(s,t,n,m);
        
        int ans =  (n-len) + (m-len);
        
        return ans;
    }
};