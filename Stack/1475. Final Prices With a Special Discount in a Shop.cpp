class Solution {
      
public:
    vector<int> finalPrices(vector<int>& prices) {
        
        // we've to find next smaller and equal to right
        
        int n = prices.size();
        stack<int> s;
        
        vector<int> ans(n, 0);
        s.push(0);
        
        for(int i=1; i<n; i++){
            int val = prices[i];
            while(!s.empty() && val <= prices[s.top()]){
                ans[s.top()] = val;
                s.pop();
            }
            
            s.push(i);
        }
        
        vector<int> solu;
        for(int i=0; i<n; i++){
            int x = prices[i] - ans[i];
            solu.push_back(x);
        }
        
        return solu;
    }
};