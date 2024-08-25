class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        // O(NlogN) approach
        
        // ith idx means that the length is i and the 
        // ith idx will contain the last element of the
        // increasing sequence
        
        vector<int> dp(n+1);
        // n+1 ki isliye bnayi bcz max length of LIS can be n
        
        for(int i=0; i<=n; i++){
            dp[i] = INT_MAX;
        }
        dp[0] = INT_MIN;
        
        for(int i=0; i<n; i++){
            int val = nums[i];
            
            auto it = upper_bound(dp.begin(), dp.end(), val); 
            int x = it - dp.begin(); 
            
            // val > dp[x-1] check krna hi pdega even though
            // hum upper bound nikaal rhe hai 
            // bcz as hume strictly increasing nikaalni hai to pichle
            //wali value equal bhi nhi honi chahiye
            // see eg -> [7,7,7,7,7,7,7]
            
            if(dp[x] > val && val > dp[x-1]){           
                dp[x] = val;
            }
            
        }
        
        int ans = -1;
        for(int i=n; i>=0; i--){
            if(dp[i] != INT_MAX){
                ans = i;
                break;
            }
        }
        
        return ans;
    }
};



////////////// O(n^2) approach //////////////

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        int dp[n];
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        
        int solu = 1;
        for(int i=1; i<n; i++){
            int ans = 0;
            for(int j=i-1; j>=0; j--){
                if(nums[i] > nums[j]){
                    ans = max(ans, dp[j]);
                }
            }
            
            dp[i] = max(dp[i], 1 + ans);
            solu = max(solu, dp[i]);
        }
        
        return solu;
    }
};