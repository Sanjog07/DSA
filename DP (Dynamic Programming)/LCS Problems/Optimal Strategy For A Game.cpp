

//  Ye 2nd wali approach hai, 1st wali approach ka code Recursion wale mei hoga
// iss wali approach mei -> Stone Game wale questions wali approach lgayi hai
// jismei hum player1 - player2 ka score return krwa rhe hai


int dp[1001][1001];
#define ll long long
class Solution{
    
    ll helper(int arr[], int i,int j){
        if(i > j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int ans1 = arr[i] - helper(arr,i+1,j);
        int ans2 = arr[j] - helper(arr,i,j-1);
        
        return dp[i][j] = max(ans1,ans2);
    }
    
    public:
    ll maximumAmount(int arr[], int n){
        
        dp[n][n];
        memset(dp, -1, sizeof dp);
        int total = accumulate(arr,arr+n,0);
        int val = helper(arr,0,n-1);
        
        int ans = (total+val)/2;
        
        return ans;
    }
};