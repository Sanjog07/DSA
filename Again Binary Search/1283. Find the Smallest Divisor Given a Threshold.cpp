
#define ll long long

class Solution {
    
    bool solve(vector<int>& nums,int n, int thres, ll div){
        ll sum = 0;
        for(int i=0; i<n; i++){
            int val = nums[i];
            sum += ceil((double)val/(double)div); 
        }
        
        if(sum <= thres){
            return true;
        }
        
        return false;
    }
    
public:
    int smallestDivisor(vector<int>& nums, int thres) {
        int n = nums.size();
        
        ll s = 1;
        ll e = *max_element(nums.begin(), nums.end()); //when thres = nums.size();
        
        ll ans = INT_MAX;
        while(s <= e){
            ll mid = (e - (e-s)/2);
            bool res = solve(nums,n,thres,mid);
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