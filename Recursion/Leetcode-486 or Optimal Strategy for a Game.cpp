

// RECURSIVE METHOD:
class Solution {
    
    int dp[21][21];
    
    // this fnc will tell max amount player 1 can get
    // i and j are starting and ending pt's of array
    int helper(vector<int>& nums,int i,int j){
        if(i > j){
            return 0;
        }
        if(i == j){
            return nums[i];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int ans1 = nums[i] + min(helper(nums,i+2,j), helper(nums,i+1,j-1));
        
        int ans2 = nums[j] + min(helper(nums,i+1,j-1),helper(nums,i,j-2));
        
        int ans = max(ans1,ans2);
        
        return dp[i][j] =  ans;
    }
    
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = n-1;
        
        dp[n][n];
        memset(dp, -1, sizeof(dp));
        
        int total = 0;
        total = accumulate(nums.begin(), nums.end(), total);
        
        int p1Score = helper(nums,i,j);
        int p2Score = total - p1Score;
        
        if(p1Score >= p2Score){
            return true;
        }
        
        return false;
    }
};


// ITERATIVE METHOD:
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        // so here we'll use the gap strategy 
        // i.e we'll do the diagonal traversal
        
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        
        for(int gap=0; gap<n; gap++){
            for(int i=0, j=gap; j<n; i++, j++){
                if(gap == 0){
                    // there will be only single element
                    dp[i][j] += nums[i];
                }else if(gap == 1){
                    // there will be 2 elements
                    dp[i][j] += max(nums[i], nums[j]);
                }else{
                    int ans1 = nums[i] + min(dp[i+2][j], dp[i+1][j-1]);
                    int ans2 = nums[j] + min(dp[i+1][j-1], dp[i][j-2]);
                    
                    dp[i][j] = max(ans1,ans2);
                }
            }
        }
        
        int ans = dp[0][n-1]; // i.e top-right corner
        
        int total = 0;
        total = accumulate(nums.begin(), nums.end(), total);
        
        int p1Score = ans;
        int p2Score = total - p1Score;
        
        if(p1Score >= p2Score){
            return true;
        }
        
        return false;        
    }
};
