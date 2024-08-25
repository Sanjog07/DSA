

// https://www.youtube.com/watch?v=OINnBJTRrMU

// Notebook

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1){
            return 0;
        }
        
        int s = 0;
        int e = n-1;
        
        while(s <= e){
            int mid = s + (e-s)/2;
            if(mid == 0 && nums[mid] > nums[mid+1]){
                return mid;
            }else if(mid == n-1 && nums[mid] > nums[mid-1]){
                return mid;
            }else if(nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1]){
                return mid;
            }else if(nums[mid] > nums[mid+1]){
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }
        
        return -1;
    }
};


















