
#define ll long long

class Solution {
    
    bool solve(vector<int>& nums, ll d, int m, int k, int n){
        int cnt = 0;
        int freq = 0;
        for(int i=0; i<n; i++){
            if(nums[i] <= d){
                freq++;
                if(freq == k){
                    freq = 0;
                    cnt++;
                    if(cnt == m){
                        return true;
                    }
                }
            }else{
                freq = 0;
            }
        }
        
        return false;
    }
    
public:
    int minDays(vector<int>& nums, int m, int k) {
        int n = nums.size();
        
        ll x = m*k;
        if(n < x){
            return -1;
        }
        
        ll s = 1;  // when all array ele's are 1
        ll e = *max_element(nums.begin(), nums.end());  // sabhi ke bloom hone ka wait krna pdega
        
        ll ans = INT_MAX;
        while(s <= e){
            ll mid = (e - (e-s)/2);
            bool res = solve(nums,mid,m,k,n);
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