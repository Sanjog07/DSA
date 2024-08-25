
// https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/discuss/1875423/C%2B%2B-easy-2-approaches

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        priority_queue<int, vector<int>, greater<int> > pq;
        
        for(int i=0; i<n; i++){
            pq.push(nums[i]);
            if(pq.size() > 2){
                pq.pop();
            }
        }
        
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        
        return (x-1)*(y-1);
    }
};