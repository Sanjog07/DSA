
// https://www.youtube.com/watch?v=ho9x_C2akHg

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        
        int s = -1, e = -1;
        for(int i=0; i<n-1; i++){
            if(nums[i+1] < nums[i]){
                s = i;
                break;
            }
        }
        
        for(int i=n-1; i>=1; i--){
            if(nums[i-1] > nums[i]){
                e = i;
                break;
            }
        }
        
        if(s == -1 && e == -1){
            // already sorted
            return 0;
        }
        
        // find the min and max ele from s to e
        // ye isliye nikaal rhe hai ki agr s se e tk sort 
        // krne ke bavjood bhi complete array sort nhi ho rhi
        // see eg -> 4 6 1 2 5 8 3 7
        
        int mine = INT_MAX;
        int maxe = INT_MIN;
        for(int i=s; i<=e; i++){
            mine = min(mine, nums[i]);
            maxe = max(maxe, nums[i]);
        }
        
        while((s-1) >= 0 && nums[s-1] > mine){
            s--;
        }
        while((e+1) < n && nums[e+1] < maxe){
            e++;
        }
        
        return e - s + 1;
                
    }
};