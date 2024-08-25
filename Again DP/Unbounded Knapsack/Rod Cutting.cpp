
int dp[1002][1002];
class Solution{
    
    int helper(int price[],int cut, int N){
        if(N == 0 || cut == 0){
            return 0;
        }
        if(dp[cut][N] != -1){
            return dp[cut][N];
        }
         
        // we'll pick the element
        int ans1 = INT_MIN, ans2 = INT_MIN;
        if(cut <= N){
            ans1 = price[cut-1] + helper(price,cut,N-cut);
        }
        
        // don't pick the element
        ans2 = helper(price,cut-1,N);
        
        return dp[cut][N] = max(ans1,ans2);
    }
    
    //     int helper(int wt[], int val[], int n, int w){
    //     if(n == 0 || w == 0){
    //         return 0;
    //     }
    //     if(dp[n][w] != -1){
    //         return dp[n][w];
    //     }
         
    //     // we'll pick the element
    //     int ans1 = INT_MIN, ans2 = INT_MIN;
    //     if(wt[n-1] <= w){
    //         ans1 = val[n-1] + helper(wt,val,n,w-wt[n-1]);
    //     }
        
    //     // don't pick the element
    //     ans2 = helper(wt,val,n-1,w);
        
    //     return dp[n][w] = max(ans1,ans2);
    // }
    
  public:
    int cutRod(int price[], int n) {
        dp[n+1][n+1];
        memset(dp, -1, sizeof(dp));
        
        return helper(price,n,n); 
        
        // int wt[n];
        // for(int i=0; i<n; i++){
        //     wt[i] = i+1;
        // }
        
        // dp[n+1][n+1];
        // memset(dp, -1, sizeof(dp));
        
        // return helper(wt,price,n,n);        
    }
};