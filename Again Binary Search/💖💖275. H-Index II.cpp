
class Solution {
public:
    int hIndex(vector<int>& nums) {
        int n = nums.size();
        
        // eg -> [20,30,40,50,60]
        if(nums[0] >= n){
            return n;
        }
        
        // ek hi case ka ans = 0 hoga, when there are all 0's
        
        // and s ko isiliye 0 se start nhi kiya bcz (n-mid) nikalte hue vo 
        // fir out if bounds chala jata when mid = 0

        int s = 1;
        int e = n;
        
        int ans = 0;
        while(s <= e){
            int mid = s + (e-s)/2;
            
            // (n-mid) se ye pta chal rha hai ki atleast itne elements 
            // ki value to mid se jyada hai as arr is sorted
            // eg-> {1 2 3 4 4 4 5 6 7} 
            if(nums[n-mid] >= mid && nums[n-mid-1] <= mid){
                ans = mid;
                s = mid + 1;
            }else{
                // see eg -> {1 2 3 4 5 6} for below if condi
                if(nums[n-mid] >= mid && nums[n-mid-1] > mid){
                    s = mid + 1;
                }else{
                    e = mid - 1;
                }
            }
        }
        
        return ans;
    }
};