


int dp[1001][1001];

class Solution{
    
    int helper(int wt[], int val[], int n, int w){
        if(n == 0 || w == 0){
            return 0;
        }
        if(dp[n][w] != -1){
            return dp[n][w];
        }
         
        // we'll pick the element
        int ans1 = INT_MIN, ans2 = INT_MIN;
        if(wt[n-1] <= w){
            ans1 = val[n-1] + helper(wt,val,n-1,w-wt[n-1]);
        }
        
        // don't pick the element
        ans2 = helper(wt,val,n-1,w);
        
        return dp[n][w] = max(ans1,ans2);
    }
    
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n){
        dp[n+1][w+1];
        memset(dp, -1, sizeof(dp));
        
        return helper(wt,val,n,w);
    }
};

