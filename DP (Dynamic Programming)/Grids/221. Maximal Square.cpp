
// https://www.youtube.com/watch?v=UagRoA3C5VQ&list=PL-Jc9J83PIiEZvXCn-c5UIBvfT8dA-8EG

// iss video mei isne ek cell ko top-left maan ke 
// end se solve krna start kiya hai
// we can also start from (0,0) by considering each cell
// as the bottom-right


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int dp[n][m];
        memset(dp , 0 , sizeof(dp));
        
        int ans = 0;
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(i == n-1 || j == m-1){
                    dp[i][j] = matrix[i][j] - '0';
                    //cout<<dp[i][j]<<" ";
                }else if(matrix[i][j] == '0'){
                    dp[i][j] = 0;
                    //cout<<dp[i][j]<<" ";
                }else{
                    dp[i][j] = 1 + min({dp[i+1][j+1] , dp[i][j+1] ,dp[i+1][j]});
                    //cout<<dp[i][j]<<" ";
                }

                
                ans = max(ans , dp[i][j]);
            }
            //cout<<endl;
        }
        
        return ans*ans;
    }
};

class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int dp[n][m];
        
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == '0'){
                    dp[i][j] = 0;
                }else if(i == 0 || j == 0){
                    dp[i][j] = mat[i][j] - '0';
                }else {
                    dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j],dp[i-1][j-1]});
                }
                
                ans = max(ans, dp[i][j]);
            }
            
        }
        
        return ans*ans;
    }
};


