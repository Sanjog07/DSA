class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        // here the elements are repeating
        
        int n = nums.size();
        int s = 0;
        int e = n-1;
        
        //int ans = -1;
        while(s <= e){
            int mid = (s+e) >> 1;
            if(nums[mid] == target){
                return true;
            }
            if(nums[mid] == nums[s] && nums[mid] == nums[e]){
                s++;
                e--;
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
        
        return false;;
    }
};
