class Solution {
public:
    int maxProfit(vector<int>& prices){
        int n = prices.size();
        
        int i = 0, ans = 0;
        while(i < n-1){
            if(prices[i+1] > prices[i]){
                ans += (prices[i+1] - prices[i]);
            }
            
            i++;
        }
        
        return ans;
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pro = 0;
        int n = prices.size();
        
        int buy = 0 , sell = 0;
        for(int i=0; i<n-1; i++){
            if(prices[i+1] < prices[i]){
                pro += (prices[sell] - prices[buy]);
                buy = sell = i+1;
            }else{
                sell++;
            }
        }
        
        pro += (prices[sell] - prices[buy]);
        
        return pro;
    }
};