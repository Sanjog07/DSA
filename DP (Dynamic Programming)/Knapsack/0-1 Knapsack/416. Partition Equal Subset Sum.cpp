

//https://leetcode.com/problems/partition-equal-subset-sum/discuss/1624390/C%2B%2B-Brute-Force-To-Optimized-SolutionO(N)-Time-or-W-Explanation
  
  PLEASE REFER THE ABOVE LINK FOR SOLUTION OF THIS PARTICULAR PROBLEM
  IN O(N) TIME -> BITSET WALA


class Solution {
    
    int dp[201][20001];
    
    int isSubsetSum(vector<int>& arr, int n, int sum){
        if(sum == 0){
            return 1; // i.e the empty subset, even when n == 0
        }
        if(n == 0){
            return 0;
        }
        if(dp[n][sum] != -1){
            return dp[n][sum];
        }
        
        int ans1 = 0, ans2 = 0;
        // pick
        if(arr[n-1] <= sum){
            ans1 = isSubsetSum(arr,n-1,sum-arr[n-1]);
        }
        
        //don't pick
        ans2 = isSubsetSum(arr,n-1,sum);
        
        return dp[n][sum] = ans1 || ans2;
    }        
    
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        
        int sum = 0;
        sum = accumulate(nums.begin(), nums.end(), sum);
        
        if(sum%2 != 0){
            return false;
        }
          
        sum = sum/2;
        dp[n][sum+1];
        memset(dp, -1, sizeof(dp));  
        
        return isSubsetSum(nums,n,sum);
    }
};