class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        int dp[n+1][n+1];
        memset(dp , 0 , sizeof(dp));
        
        string c = s;
        reverse(c.begin() , c.end());
        
        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }else if(c[i-1] == s[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        // for(int i=0; i<=n; i++){
        //     for(int j=0; j<=n; j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return dp[n][n];
    }
};