
// Refer Pepcoding Video



// yha pe hum sell state ke baad hi buy state mei aa skte hai
// jb tk ek stock ko sell nhi kr dete tb tk agla stock
// buy nhi kr skte
class Solution {
public:
    int maxProfit(vector<int>& arr, int fee) {
        int n = arr.size();
        
        int obsp = -arr[0]; // buying state profit
        int ossp = 0; // sell state profit
        
        
        for(int i=1; i<n; i++){
            int nbsp, nssp;
            if((ossp-arr[i]) > obsp){
                nbsp = (ossp-arr[i]);
            }else{
                nbsp = obsp;
            }
            if((arr[i] + obsp - fee) > ossp){
                nssp = (arr[i] + obsp - fee);
            }else{
                nssp = ossp;
            }
            
            obsp = nbsp;
            ossp = nssp;
        }
        
        return ossp;
    }
};






// so this approch will give TLE -> O(n^2)

class Solution {
    
   int dp[50002];
   int solve(vector<int>& prices, int fee,int i,int n){
        if(i >= n){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        
        int ans = INT_MIN;
        for(int j=i+1; j<n; j++){
            int x = prices[j] - prices[i] - fee;
            if(x > 0){
                int val1 = x + solve(prices,fee,j+1,n);
                ans = max(ans, val1);
            }
        }
        
        int val2 = solve(prices,fee,i+1,n);
        ans = max(ans, val2);
        
        return dp[i] = ans;
        
   }
    
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        
        dp[n];
        memset(dp, -1, sizeof dp);
        
        return solve(prices, fee,0,n);
        
    }
};