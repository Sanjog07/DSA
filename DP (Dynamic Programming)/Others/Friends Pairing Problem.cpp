int mod = 1e9+7; 
#define ll long long
    
class Solution{
    
    ll dp[10002];
    ll helper(int n){
        if(n <= 0){
            return 0;
        }
        if(n == 1 || n == 2){
            return n;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        
        // ya to usko single rkh lo
        ll ans1 = helper(n-1)%mod;
        
        // ya usko pair kr do -> ab pair kiske saath kre
        // uske (n-1) options hai
        ll ans2 = ((n-1)%mod * helper(n-2)%mod)%mod;
        
        ll ans = (ans1 + ans2)%mod;
        
        return dp[n] = ans;
    }
    
public:
    int countFriendsPairings(int n){
        dp[n+1];
        memset(dp, -1, sizeof dp);
        
        return helper(n);
    }
};