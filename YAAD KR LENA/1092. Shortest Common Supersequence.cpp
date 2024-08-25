class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        
        int dp[n+1][m+1];
        memset(dp, 0, sizeof(dp));
        
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }else if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        int i = n, j = m;
        string ans = "";
        while(i > 0 && j > 0){
            if(str1[i-1] == str2[j-1]){
                ans += str1[i-1];
                i--;
                j--;
            }else{
                if(dp[i][j-1] > dp[i-1][j]){
                    // ye wali cheez ka reson mt find kro thoda observation hai
                    // ki why yha pe str2 ka (j-1)th character liya
                    ans += str2[j-1];
                    j--;
                }else{
                    ans += str1[i-1];
                    i--;
                }
            }
        }
        
        while(i > 0){
            ans += str1[i-1];
            i--;
        }
        
        while(j > 0){
            ans += str2[j-1];
            j--;
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};