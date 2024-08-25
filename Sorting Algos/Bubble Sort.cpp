
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        
        // BUBBLE SORT
        
        // i ko n-1 chalane ka means ki i-1 elements apni shi jagha pr phuch gye
        for(int i=1; i<=n-1; i++){
            for(int j=0; j<=(n-i-1); j++){
                if(nums[j] > nums[j+1]){
                    int temp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = temp;
                }
            }
        }
    }
};