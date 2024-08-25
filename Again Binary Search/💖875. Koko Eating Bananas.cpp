
#define ll long long

// notebook

class Solution {
    
    bool solve(vector<int>& nums,int n,ll cnt, int h){
        
        ll ans = 0;
        
        for(int i=0; i<n; i++){
            int val = nums[i];
                
            if(val < cnt){
                ans += 1;
            }else{
                
                // CEIL() KO DHYAAN SE USE KIYA KRO
                // YE DOUBLE VAL ACCEPT KRTA HAI VRNA GALAT ANS DEGA
                ans += ceil((double)val/(double)cnt);
            }
        }
        
        if(ans <= h){
            return true;
        }
        
        return false;
    }     
    
    
    
    // TLE
    
//     bool solve(vector<int>& nums,int n,ll cnt, int h){
        
//         ll ans = 0;
        
//         for(int i=0; i<n; i++){
//             int val = nums[i];
            
//             int hrs = 1;
//             while(val > cnt){
//                 val -= cnt;
//                 hrs++;
//             }
            
//             ans += hrs;
//         }
        
//         if(ans <= h){
//             return true;
//         }
        
//         return false;
//     }    
    
public:
    int minEatingSpeed(vector<int>& nums, int h) {
        int n = nums.size();
        
        ll s = 1;
        ll e = *max_element(nums.begin(), nums.end());
        
        ll ans = INT_MAX;
        while(s <= e){
            ll mid = (e - (e-s)/2);
            bool res = solve(nums,n,mid,h);
            if(res){
                ans = mid;
                e = mid-1;
            }else{
                s = mid+1;
            }            
        }
        
        return ans;
    }
};