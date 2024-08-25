//////////  TOP-DOWN    /////////////

class Solution {
    
    int dp[1000];
    
    int helper(vector<int>& cost,int i,int n){
        if(i >= n){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        
        //ek particular idx se hum 1 ya 2 ki jump maar skte hai
        
        // if 1 ki jump maare
        int res1 = helper(cost,i+1,n);
        
        // if 2 ki jump maare
        int res2 = helper(cost,i+2,n);
        
        return dp[i] =  cost[i] + min(res1,res2);
    }
    
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        dp[n];
        memset(dp,-1,sizeof(dp));
        
        // either we'll start from idx 0 or 1 
        int ans1 = helper(cost,0,n);
        int ans2 = helper(cost,1,n);
            
        return min(ans1,ans2);
    }
};

//////////    BOTTOM-UP    /////////////
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        int dp[n];
        // so here at each idx we'll store ki -> iss idx pr aane ke 
        // liye hume kitni min cost bharni pdegi
        
        
        // as hum in dono mei se kisi bhi pos se start kr skte hai
        // to inpe direct aa skte hai
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        for(int i=2; i<n; i++){
            dp[i] = cost[i] + min(dp[i-1],dp[i-2]); 
            // ye min wale ke andar aisa isliye likha bcz hum ek pos pe
            // ya to 1 jump se aa skte hai ya 2 jump se
        }
        
        // and hume i == n pe phuchna hai, so vha pe ya to (n-1) pos 
        // se phuch skte hai ya (n-2) se
        
        return min(dp[n-1], dp[n-2]);
    }
};


