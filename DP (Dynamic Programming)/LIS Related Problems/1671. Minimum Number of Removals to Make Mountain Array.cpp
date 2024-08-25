
// this ques is almost same as of Longest Bitonic subsequence
// bss thoda sa diff hai -> see explaination in copy 

class Solution {
    
    void LIS(vector<int>& nums,vector<int> &dp){
        int n = nums.size();

        for(int i=1; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }
        
        return;
    }    
    
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> lis(n, 1);
        LIS(nums, lis);
        
        vector<int> lds(n, 1);
        reverse(nums.begin(),nums.end());
        
	    LIS(nums, lds);

	    reverse(lds.begin(),lds.end());
	    
	    int ans = INT_MIN;
	    for(int i=1; i<n-1; i++){
            if(lis[i] != 1 && lds[i] != 1){
    	        int val = lis[i] + lds[i] - 1;
                //ans = max(ans, val);
                if(val > ans){
                    ans = val;
                }                
            }

	    }
	    
	    return n - ans;    
    }
};