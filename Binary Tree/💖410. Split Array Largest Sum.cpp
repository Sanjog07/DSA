#define ll long long

// https://www.youtube.com/watch?v=nYjriZ-nBtw

class Solution {
    
    bool check(vector<int>& nums, int m,int val){
        int cnt = 1;
        int n = nums.size();
        
        int tot = 0;
        for(int i=0; i<n; i++){
            if(nums[i] > val){
                return false;
            }
            if((tot + nums[i]) > val){
                cnt++;
                tot = nums[i];
            }else{
                tot += nums[i];
            }
        }
        
        // ye sirf = pe nhi < pe bhi true return krna hai
        // bcz < wale case mei bhi hume r = mid-1 krna hoga
        // see eg[1,4,4], m = 3
        
        if(cnt <= m){
            return true;
        }
        
        return false;
    }
    
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        
        ll sum = 0;
        sum = accumulate(nums.begin(), nums.end(), sum);
        
        if(m == 1){
            return sum;
        }
        
        ll l = *min_element(nums.begin(), nums.end());
        ll r = sum;
        
        int ans = INT_MAX;
        while(l <= r){
            ll mid = (l+r)/2;
            if(check(nums, m, mid)){
                //ans = min(ans, mid);
                if(mid < ans){
                    ans = mid;
                }
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        
        return ans;
    }
};