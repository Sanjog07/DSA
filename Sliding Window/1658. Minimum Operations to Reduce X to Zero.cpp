#define ll long long

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // here all the elements of the given array are positive
        // so hum yha pe largest subarray with sum == tar nikalenge
        // where tar = total - x;
        // so uske alawa jo elements ka sum hoga, vo == x hoga
        // and vo smallest length bhi hogi
        // and humko min operations hi nikalne hai
        
        int n = nums.size();
        // Longest subarray with sum == tar
        
        int total = 0;
        for(int i=0; i<n; i++){
            total += nums[i];
        }
        
        int tar = total - x;
        if(tar < 0){
            return -1;
        }else if(tar == 0){
            return n;
        }
        

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
        
        //cout<<ans<<endl;
        if(ans != INT_MIN){
            return n - ans;
        }        
        
        return -1;        
    }
};