

int dp[101][100001];

class Solution{ 
    
    int helper(int arr[], int n, int sum){
        if(sum == 0){
            return 1; // i.e the empty subset, even when n == 0
        }
        if(n == 0){
            return 0;
        }
        if(dp[n][sum] != -1){
            return dp[n][sum];
        }
        
        int ans1 = 0, ans2 = 0;
        // pick
        if(arr[n-1] <= sum){
            ans1 = helper(arr,n-1,sum-arr[n-1]);   
        }
        
        //don't pick
        ans2 = helper(arr,n-1,sum);
        
        return dp[n][sum] = ans1 || ans2;
    }
    
public:
    bool isSubsetSum(int n, int arr[], int sum){
        dp[n+1][sum+1];
        memset(dp, -1, sizeof(dp));
        
        return helper(arr,n,sum);
    }
};