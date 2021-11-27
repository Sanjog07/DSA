class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        // O(LOGN) using Binary Search
        
        int n = nums.size();
        
        int s = 0;
        int e = n-1;
        
        if(n == 1){
            return 0;
        }
        
        while(s <= e){
            int mid = (s+e) >> 1;
            if((mid == 0 && nums[mid] > nums[mid+1]) || (mid == n-1 && nums[mid] > nums[mid-1])){
                return mid;
            }else{
                if(mid == 0){
                    return 1;
                }else if(mid == n-1){
                    return mid-1;
                }
            }
            
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                return mid;
            }else if(nums[mid] > nums[mid-1]){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
               
        }
               
        return -1;
        
        
//         // O(N) solution using maps
//         map<int,int> m;
//         int n = nums.size();
        
//         for(int i=0; i<n; i++){
//             m[nums[i]] = i;
//         }
        
        
//         //as humne map liya hai unordered map nhi to ye sorted hoga
//         // and array ka max element bhi one of the peak element hoga
//         // so hum max element return krenge
        
//         auto it = m.rbegin(); 
//         // m.end() work nhi krega bcz vo last element ke next 
//         // pe pt krta hai
        
        
//         return it->second;
    }
};