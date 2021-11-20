#define ll long long
class Solution{
    public:
    int lenOfLongSubarr(int nums[],  int n, int tar){
        // agr yha pe -ve no's ho to ye sliding window se nhi hoga
        // ye humne map se hi solve krna pdega
        
        int l=0, r=0;
        ll sum = 0;
        int ans = INT_MIN;
        
        while(l <= r && r < n){
            sum += nums[r];
            
            if(sum == tar){
                ans = max(ans, (r-l+1));
                // sum -= nums[l];
                // l++;                
            }else if(sum > tar){
                while(sum > tar && l <= r){
                    sum -= nums[l];
                    l++;
                    if(sum == tar){
                        ans = max(ans, (r-l+1));       
                        // sum -= nums[l];
                        // l++;            
                    }
                }                
            }
            r++;
        }
        
        if(ans == INT_MIN){
            return 0;
        }        
        
        return ans;         
    }
};