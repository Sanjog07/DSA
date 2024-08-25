
// NOTEBOOK

class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size();
        
        int i=0, j=n-1;
        
        int ans = 0;
        int val;
        while(i < j){
            if(nums[i] <= nums[j]){
                val = (nums[i] * (j-i));
                i++;
            }else{
                val = (nums[j] * (j-i));
                j--;
            }
            
            ans = max(ans, val);
        }
        
        return ans;
    }
};
