class Solution {
public:
    int search(vector<int>& nums, int target) {
        // so basically rorated and sorted array mei
        // agr hum ek idx pe hai to uski left side 
        // ya uski right side i.e ek side to pakka 
        // sorted hogi and then hum sorted side mei
        // binary search lgake apna tar search 
        // kr skte hai
        
        SOLUTION LINK: https://www.youtube.com/watch?v=r3pMQ8-Ad5s
        
        // agr else if mei hum nums[s] < nums[mid] tk hi lgate hai
        // to and not nums[s] <= nums[mid]
        // to n == 2 wale cases fass skte hai
        // e.g -> [3,1]
        
        
        int n = nums.size();
        int s = 0;
        int e = n-1;
        
        int ans = -1;
        while(s <= e){
            int mid = (s+e) >> 1;
            if(nums[mid] == target){
                return mid;
            }
            
            // if left part is sorted
            else if(nums[s] <= nums[mid]){
                if(target >= nums[s] && target <= nums[mid]){
                    e = mid-1;
                }else{
                    s = mid+1;
                }
                
                // if right part is sorted
            }else{
                if(target >= nums[mid] && target <= nums[e]){
                    s = mid+1;
                }else{
                    e = mid-1;
                }
            }
        }
        
        return ans;
    }
};