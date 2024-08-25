
// https://www.youtube.com/watch?v=kd0-hUwISDo

class Solution {
    
    int kadane(vector<int>& nums){
        int n = nums.size();
        
        int cs = 0;
        int ms = INT_MIN;
        
        for(int i=0; i<n; i++){
            cs += nums[i];
            
            if(cs < 0){
                cs = 0;
            }     
            
            ms = max(cs, ms);
        }
        
        return ms;
    }
    
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        
        // if all the elements are -ve
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(nums[i] < 0){
                cnt++;
            }
        }
        if(cnt == n){
            return *max_element(nums.begin(), nums.end());
        }
        
        int a = kadane(nums);
        
        int sum = 0;
        sum = accumulate(nums.begin(), nums.end(), sum);
        
        for(int i=0; i<n; i++){
            nums[i] *= -1;
        }
        
        int b = kadane(nums);
        b *= -1;
        
        int c = sum - b;
        
        return max(a,c);
    }
};