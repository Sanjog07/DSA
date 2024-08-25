
// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/discuss/1409763/C%2B%2B-easy-solution-with-explanation


int mod = 1000000007;
#define ll long long

class Solution {
    
    ll fastPow(ll x,ll y){
        if(y == 0){
            return 1;
        }
        
        ll smallAns = fastPow(x,y/2);
        smallAns = ((smallAns%mod) * (smallAns%mod))%mod;
        
        if(y%2 == 0){
            return smallAns%mod;
        }
        
        return ((x%mod) * (smallAns%mod))%mod;
    }
    
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
        
        int i=0, j=n-1;
        int ans = 0;
        while(i <= j){
            if((nums[i] + nums[j]) > target){
                j--;
            }else{
                int x = j-i;
                ans = ((ans%mod) + (fastPow(2,x)%mod))%mod;
                i++;
            }
        }
        
        return ans%mod;
    }
};