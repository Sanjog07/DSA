

////  O(N^2) //////

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        
        int dp[n][n];
        memset(dp, -1, sizeof(dp));
        
        string ans = "";
        for(int gap=0; gap<n; gap++){
            for(int i=0,j=gap; j<n; i++,j++){
                if(gap == 0){
                    dp[i][j] = 1;
                }else if(gap == 1){
                    // it means yha pe string of len == 2 hogi
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
                    ans = s.substr(i, gap+1);
                }
            }
        }
        
        return ans;        
    }
};



///    O(N^3) /////

// class Solution {
    
//     bool isPalindrome(string s){
//         string str = s;
        
//         reverse(s.begin(),s.end());
        
//         return str == s;
//     }
    
    
// public:
//     string longestPalindrome(string s) {
//         int n = s.length();
//         int dp[n+1][n+1];
//         memset(dp , 0 , sizeof(dp));
        
//         string c = s;
//         reverse(c.begin() , c.end());
        
//         for(int i=0; i<=n; i++){
//             for(int j=0; j<=n; j++){
//                 if(i == 0 || j == 0){
//                     dp[i][j] = 0;
//                 }else if(s[i-1] == c[j-1]){
//                     dp[i][j] = 1 + dp[i-1][j-1];
//                 }else{
//                     dp[i][j] = 0;
//                 }
//             }
//         }
        
//         int ans = 0;
//         int l=0,r=0;
//         string solu = "";
//         for(int i=0; i<=n; i++){
//             for(int j=0; j<=n; j++){
//                 //ans = max(ans , dp[i][j]);
//                 if(dp[i][j] > ans){
                    
                    
//                     // i.e yha pe original string s, jo hai vo row pe hai -> i.e i and reversed wali col i.e j pe hai
                    
//                     string str = s.substr(i - dp[i][j], dp[i][j]);
                    
//             // or it can we written as - c.substr(j - dp[i][j], ...);
                    
//                     if(isPalindrome(str)){
//                         ans = dp[i][j];
//                         solu = str;
//                     }
//                 }

//             }
//         }
        
//         return solu;
//     }
// };