
/ https://leetcode.com/problems/stone-game/discuss/1708217/C%2B%2B-2-Solutions-O(1)-Logic-and-DP-Approach



/ https://www.youtube.com/watch?v=ww4V7vRIzSk&t=1658s 
ISS VIDEO KO FIRST 4 MIN TK DEKH LO


class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};

class Solution {
    
    int dp[501][501];
    int helper(vector<int>& nums,int i,int j){
        if(i > j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int ans1 = nums[i] + min(helper(nums,i+2,j), helper(nums,i+1,j-1));
        
        int ans2 = nums[j] + min(helper(nums,i+1,j-1),helper(nums,i,j-2));
        
        //int ans = max(ans1,ans2);
        
        return dp[i][j] =  max(ans1,ans2);
    }    
    
public:
    bool stoneGame(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = n-1;
        
        dp[n][n];
        memset(dp, -1, sizeof(dp));
        
        int total = 0;
        total = accumulate(nums.begin(), nums.end(), total);
        
        int p1Score = helper(nums,i,j);
        int p2Score = total - p1Score;
        
        if(p1Score > p2Score){
            return true;
        }
        
        return false;    
    }
};

// class Solution {
    
//     int dp[501][501];
    
//     int helper(vector<int>& piles,int i,int j){
//         if(i > j){
//             return 0;
//         }
//         if(dp[i][j] != -1){
//             return dp[i][j];
//         }
        
//         int ans1 = piles[i] + min(helper(piles,i+2,j), helper(piles,i+1,j-1));
        
//         int ans2 = piles[j] + min(helper(piles,i,j-2), helper(piles,i+1,j-1));
        
//         return dp[i][j] = max(ans1,ans2);
        
//     }
    
// public:
//     bool stoneGame(vector<int>& piles) {
//         int n = piles.size();
        
//         int dp[n][n];
//         memset(dp, -1, sizeof(dp));
        
//         int total_stones = 0;
//         total_stones = accumulate(piles.begin(),piles.end(), total_stones);
        
//         int alice_stones = helper(piles,0,n-1);
        
//         cout<<alice_stones<<"----";
        
//         int bob_stones = total_stones - alice_stones;
        
//         cout<<bob_stones<<"...";
        
//         if(alice_stones >= bob_stones){
//             return true;
//         }
        
//         return false;
//     }
// };