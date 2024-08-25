class Solution {
public:
    int minCut(string s) {
        int n = s.length();

        bool mat[n][n];
        for(int gap=0; gap<n; gap++){
            for(int i=0, j=gap; j<n; i++,j++){
                if(gap == 0){
                    mat[i][j] = true;
                }else if(gap == 1){
                    mat[i][j] = (s[i] == s[j]);
                }else{
                    if(s[i] == s[j]){
                        mat[i][j] = mat[i+1][j-1];
                    }else{
                        mat[i][j] = false;
                    }
                }
            }
        }
        
        
        int dp[n];
        dp[0] = 0;
        for(int i=1; i<n; i++){
            if(mat[0][i]){
                dp[i] = 0;
            }else{
                int ans = INT_MAX;
                for(int j=i; j>0; j--){
                    if(mat[j][i]){
                        int val = 1 + dp[j-1];
                        ans = min(ans, val);
                    }
                }  
                
                dp[i] = ans;
            }

        }
        
        return dp[n-1];
    }
};



class Solution {
    
    int dp[2002][2002];
    bool isPalindrome(string &str,int s,int e){
        while(s < e){
            if(str[s] != str[e]){
                return false;
            }
            s++;
            e--;
        }
        
        return true;
    }
    
    
    int solve(string &s,int i,int j){
        if(i >= j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(isPalindrome(s,i,j)){
            return dp[i][j] = 0;
        }
        
        int ans = INT_MAX;
        for(int k=i; k<j; k++){
            if(isPalindrome(s,i,k)){
                int val = 1 + solve(s,k+1,j);
                ans = min(ans, val);
            }
        }
        
        return dp[i][j] = ans;
    }
    
public:
    int minCut(string s) {
        int n = s.length();
        
        dp[n][n];
        memset(dp, -1, sizeof(dp));
        return solve(s,0,n-1);
    }
};



class Solution {
    
    int dp[2002][2002];
    int pal[2002][2002];
    bool isPalindrome(string s,int i,int j){
        if(pal[i][j] != -1){
            return pal[i][j];
        }
        while(i < j){
            if(s[i] != s[j]){
                pal[i][j] = 0;
                return false;
            }
            i++;
            j--;
        }
        
        pal[i][j] = 1;
        return true;
    }
    
    int solve(string s,int i,int j){
        if(i >= j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(isPalindrome(s,i,j)){
            return dp[i][j] = 0;
        }
        
        int solu = INT_MAX;
        for(int k=i; k<j; k++){
            int ans1 = solve(s,i,k);
            int ans2 = solve(s,k+1,j);
            
            int ans = 1 + ans1 + ans2;
            
            solu = min(solu, ans);
        }
        
        return dp[i][j] = solu;
    }
    
public:
    int minCut(string s) {
        int n = s.length();
        
        dp[n][n];
        pal[n][n];
        memset(dp, -1, sizeof dp);
        memset(pal, -1, sizeof pal);
        
        return solve(s,0,n-1);
    }
};