class Solution{
    public:
    
    int longestCommonSubstr(string s1, string s2, int n, int m){
        int dp[n+1][m+1];
        memset(dp , -1 , sizeof(dp));
        
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }else if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        
        int ans = INT_MIN;
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                ans = max(ans , dp[i][j]);
            }
        }
        
        return ans;
    }
};

// Memoization to find longest common subarray 
//(works identically for substring, just replace vector with string).
int findLongestCommonLen(vector<string>& a, vector<string>& b, int n, int m, int& res, vector<vector<int>>& dp, int& resRow, int& resCol){
  if(n==0 || m==0) return 0;
  
  int isSame = 0;
  if(dp[n][m] != -1) return dp[n][m];

  if(a[n-1] == b[m-1]){
    isSame = 1 + findLongestCommonLen(a, b, n-1, m-1, res,dp, resRow, resCol);
    if(isSame > res){
      resRow = n;
      resCol = m;
      res = isSame;
    }
  }
  else {
    //Make recursive calls
    findLongestCommonLen(a, b, n-1, m, res, dp, resRow, resCol);
    findLongestCommonLen(a, b, n, m-1, res, dp, resRow, resCol);

    isSame = 0;
  }
  return dp[n][m] = isSame;
}