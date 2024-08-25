class Solution{
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
	int LongestBitonicSequence(vector<int>nums){
	    int n = nums.size();
	    
        vector<int> lis(n, 1);
        LIS(nums, lis);
        
        vector<int> lds(n, 1);
        reverse(nums.begin(),nums.end());
        
        // hum yha LDS ke liye alag se func nhi bna rhe -> LIS ka hi use kr rhe hai
	    LIS(nums, lds);

        // ye step krna bhool skte hai to isko yaad rkhna
	    reverse(lds.begin(),lds.end());
	    
	    int ans = INT_MIN;
	    for(int i=0; i<n; i++){
	        int val = lis[i] + lds[i] - 1;
	        ans = max(ans, val);
	    }
	    
	    return ans;
	}
};