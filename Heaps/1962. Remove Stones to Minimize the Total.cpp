class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        
        int sum = 0;
        sum = accumulate(piles.begin(), piles.end(), sum);
        
        priority_queue<int> pq(piles.begin(), piles.end());
        
        while(k--){
            int x = pq.top();
            pq.pop();
            int y = floor(x/2);
            pq.push(x-y);
            
            sum -= y;
        }
        
        return sum;
    }
};