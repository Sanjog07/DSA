class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        
        int first = INT_MAX, second = INT_MAX;
        
        for(int i=0; i<n; i++){
            int val = nums[i];
            if(val < first){
                first = val;
            }else if(val > first && val < second){
                second = val;
            }else if(val > second){
                return true;
            }
        }
        
        return false;
    }
};