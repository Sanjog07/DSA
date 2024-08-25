
#define ll long long

class Solution {
    
    bool canAllocate(vector<int>& arr, ll k, ll n, ll mid){
        ll cnt = 0;
        for(ll i=0; i<n; i++){
            cnt += arr[i]/mid;
        }
        
        return cnt >= k;
    }
    
public:
    int maximumCandies(vector<int>& arr, long long k) {
        ll n = arr.size();
        
        ll s = 1;
        ll e = *max_element(arr.begin(), arr.end());
        
        int ans = 0;
        while(s <= e){
            ll mid = e - (e - s)/2;
            bool check = canAllocate(arr, k, n, mid);
            if(check){
                ans = mid;
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }
        
        return ans;
    }
};