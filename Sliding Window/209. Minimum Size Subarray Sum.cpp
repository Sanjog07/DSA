#define ll long long

class Solution {
public:
    int minSubArrayLen(int tar, vector<int>& arr) {
        int n = arr.size();
        
        int l=0, r=0;
        ll sum = 0;
        int ans = INT_MAX;
        
        while(l <= r && r < n){
            sum += arr[r];
            
            if(sum >= tar){
                while(sum >= tar){
                    ans = min(ans, (r-l+1));
                    // if((r-l+1) < ans){
                    //     ans = (r-l+1);
                    // }
                    sum -= arr[l];
                    l++;
                }
            }
            r++;
        }
        
        if(ans == INT_MAX){
            return 0;
        }        
        
        return ans;
    }
};