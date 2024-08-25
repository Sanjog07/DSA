
// https://www.youtube.com/watch?v=tHNsZHXnYd4

class Solution {
public:
    int maxProduct(vector<int>& nums){
        int n = nums.size();
        
        int ma = nums[0],mi = nums[0], ans = nums[0];
        
        for(int i=1; i<n; i++){
            if(nums[i] < 0){
                swap(ma, mi);
            } 
            
            ma = max(nums[i], nums[i]*ma);
            mi = min(nums[i], nums[i]*mi);
            
            ans = max(ans, ma);
        }
        
        
        return ans;
    }
};