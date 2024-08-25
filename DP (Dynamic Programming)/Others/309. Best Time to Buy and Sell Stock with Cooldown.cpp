
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/1706342/Recursive-Approach-is-most-intuitive-or-C%2B%2B-or-Memoization-or-189ms

// this is O(n^2) approch so n agr jyada hoga to ye TLE dega

// 714. Best Time to Buy and Sell Stock with Transaction Fee ->
// ye ques bhi same approach se ho to jayega but TLE aayegi n large ke liye

// O(n) wala solu hai dono problems ka -> baad mei dekh lena



////////////  O(n) wali approch -> ////////
class Solution {
public:
    int maxProfit(vector<int>& arr){
        int n = arr.size();
        
        int obsp = -arr[0];
        int ossp = 0;
        int ocsp = 0;
        
        for(int i=1; i<n; i++){
            int nbsp,nssp,ncsp;
            
            if((ocsp - arr[i]) > obsp){
                nbsp = (ocsp - arr[i]);
            }else{
                nbsp = obsp;
            }
            if((arr[i] + obsp) > ossp){
                nssp = (arr[i] + obsp);
            }else{
                nssp = ossp;
            }
            if(ossp > ocsp){
                ncsp = ossp;
            }else{
                ncsp = ocsp;
            }            
            
            obsp = nbsp;
            ossp = nssp;
            ocsp = ncsp;

        }
        
        return ossp;
    }
};



    // Recursive approach is very intuitive
    
    // In this problem extra constraint is given that is cooldown = > After you sell your stock, you cannot 
    // buy stock on the next day (i.e., cooldown one day).
    
    int findMax(vector<int>& prices, int curr, int n, vector<int>&dp)
    {
        if(curr>=n)
            return 0;
        
        if(dp[curr]!=-1)
            return dp[curr];
        
        //Now find all the positions where we can sell the stock
        int maxVal = 0;
        for(int i=curr+1;i<n;++i)
            if(prices[curr]<prices[i])  // We can try to sell on ith day
                //We have 2 choices
                //1.We can sell the stock at ith day and findMax from (i+2)th day
                //2.We don't sell the stock on ith day
                maxVal = max(maxVal, (prices[i]-prices[curr])+findMax(prices, i+2, n, dp));//(i+1)th day is cooldown
        
        maxVal = max(maxVal, findMax(prices,curr+1,n,dp)); // Exclude current element
        dp[curr] = maxVal;
        return maxVal;
    }
    
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        vector<int>dp(n+1,-1);
        return findMax(prices,0,n,dp);
    }