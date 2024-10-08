class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        
        while(nums.size() > 1){
            for(int i=0; i<nums.size()-1; i++){
                nums[i] = ((nums[i]%10) + (nums[i+1]%10))%10;
            }
            
            nums.pop_back();
        }
        
        return nums[0];
    }
};