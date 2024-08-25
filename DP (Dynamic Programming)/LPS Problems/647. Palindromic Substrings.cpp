class Solution {
public:
    int countSubstrings(string s) {
        int n =s.length();
        
        int dp[n][n];
        memset(dp, -1, sizeof(dp));
        
        int cnt = 0;
        for(int gap=0; gap<n; gap++){
            for(int i=0,j=gap; j<n; i++,j++){
                if(gap == 0){
                    dp[i][j] = 1;
                }else if(gap == 1){
                    // it means yha pe string of len == 2 hongi
                    if(s[i] == s[j]){
                        dp[i][j] = 1;
                    }else{
                        dp[i][j] = 0;
                    }
                }else{
                    if(s[i] == s[j]){
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
                
                if(dp[i][j] == 1){
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};