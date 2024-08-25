class Solution{
    
    int dp[102][102];
    int solve(int arr[],int i,int j){
        if(i >= j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int solu = INT_MAX;
        for(int k=i; k<j; k++){
            int c1 = solve(arr,i,k);
            int c2 = solve(arr,k+1,j);
            int c3 = arr[i-1]*arr[k]*arr[j];
            
            int ans = c1+c2+c3;
            
            solu = min(solu, ans);
        }
        
        return dp[i][j] = solu;
    }
    
public:
    int matrixMultiplication(int n, int arr[]){
        dp[n][n];
        memset(dp ,-1 , sizeof dp);
        
        return solve(arr,1,n-1);
    }
};