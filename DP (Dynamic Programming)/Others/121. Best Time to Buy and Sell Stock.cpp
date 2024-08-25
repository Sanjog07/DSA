class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int mval = INT_MIN;
        int ans = 0;
        
        for(int i=n-1; i>=0; i--){
            int x = prices[i];
            mval = max(mval, x);
            
            ans = max(ans, (mval-x));
        }
        
        return ans;
    }
};
