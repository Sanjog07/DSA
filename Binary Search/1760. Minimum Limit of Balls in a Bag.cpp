
bool canMidBeAns(vector<int>& nums, int maxOperations, int mid){
    int n = nums.size();
    
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(nums[i] > mid){
            if((nums[i]%mid) == 0){
                cnt += (nums[i]/mid) - 1;
            }else{
                cnt += (nums[i]/mid);
            }
        }
    
    }
    
    if(cnt > maxOperations){
        return false;
    }
    
    return true;
}

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size();
        
        int s = 1;
        int e = *max_element(nums.begin(), nums.end());
        
        int ans = -1;
        while(s <= e){
            int mid = (s+e) >> 1;
            
            // hum check krenge ki mid ans ho skta hai ya nhi
            bool check = canMidBeAns(nums,maxOperations,mid);
            if(check){
                ans = mid;
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }
        
        return ans;
    }
};