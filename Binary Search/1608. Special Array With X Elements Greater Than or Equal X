class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int s = 0;
        int e = *max_element(nums.begin(), nums.end());
        
        while(s <= e){
            int mid = (s+e) >> 1;
            int a = lower_bound(nums.begin(), nums.end(), mid) - nums.begin();
            int x = n - a;
            if(mid == x){
                return mid;
            }else if(x > mid){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }
        
        return -1;
    }
};