

// O(n) Solution
// https://www.youtube.com/watch?v=a9r98S-pDvk&t=600s
// ye wala solu Observation based hai
// and greedy solu hai


class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        int maxReach = 0;
        int currReach = 0;
        int jumps = 0;
        
        // n-2 tk hi chalayege
        for(int i=0; i<n-1; i++){
            
            maxReach = max(maxReach, i + nums[i]);
            
            // i == n-1 ye condi kabhi aayegi hi nhi bcz loop hi
            // n-2 tk hi chalaya hai
            // and iski koi zarurat bhi nhi hai
            // bcz agr i == n-1 wali condi aati to vo iss wali if condi
            // mei jaake jumps ke count ko bdha deta, jiski koi 
            // zarurat nhi hai bcz hume n-1 pe hi reach krna tha
            // that's why we're running our loop till n-2
            
            if(i == currReach){
                jumps++;
                currReach = maxReach;
            }
        }
        
        return jumps;
    }
};


// // class Solution {
    
// //     int dp[10002];
// //     int solve(vector<int>& nums,int n,int i){
// //         if(i >= n){
// //             return 0;
// //         }
// //         if(i == n-1){
// //             return 0;
// //         }
// //         if(dp[i] != -1){
// //             return dp[i];
// //         }
        
// //         int solu = INT_MAX-1;
// //         for(int jump=1; jump<=nums[i]; jump++){
// //             int ans = 1 + solve(nums,n,i+jump);
// //             solu = min(solu, ans);
// //         }
        
// //         return dp[i] = solu;
// //     }
    
// // public:
// //     int jump(vector<int>& nums) {
// //         int n = nums.size();
// //         if(n == 1){
// //             return 0;
// //         }
// //         if(nums[0] == 0){
// //             return -1;
// //         }
        
// //         dp[n];
// //         memset(dp, -1 , sizeof dp);
        
// //         return solve(nums,n,0);
// //     }
// // };



// // iss ques mei botttom-up wali approch mei aise nhi sochna ki
// // min no of jumps to reach at this idx -> this method 
// // will be O(n^2) -> TLE

// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         int n = nums.size();
//         if(n == 1){
//             return 0;
//         }
//         if(nums[0] == 0){
//             return -1;
//         }
        
// //         vector<int> dp(n, INT_MAX);
        
// //         dp[0] = 0;
        
//         // Ye wala method nhi chalega as it is O(n^2)
//         // for(int i=1; i<n; i++){
//         //     for(int j=0; j<i; j++){
//         //         int req = (i-j);
//         //         if(nums[j] >= req){
//         //             dp[i] = min(dp[i], dp[j] + 1);
//         //         }
//         //     }
//         // }
        
        
//         // it'll work bcz it is  -> O(n * nums[i]);
//         // nums[i] -> denoting the no of jumps -> jumos wala loop
        
// //         for(int i=0; i<n-1; i++){
// //             int jumps = nums[i];
// //             for(int j=1; j<=jumps; j++){
// //                 if((i+j) < n){
// //                     dp[i+j] = min(dp[i+j], dp[i] + 1);
// //                 }
// //             }
// //         }
        
        
//         // Actual Bottom-Up approch -> ye upar wali bhi almost 
//         // recursive code hi hai 
        
//         // Bottom-Up mei aise sochna hai ki min no of jumps to reach at         // end from this idx -> bss ismei iteration end se start krnege
//         // bcz chhoti problem is at last idx
        
//         vector<int> dp(n, INT_MAX-1);
        
//         dp[n-1] = 0;
//         for(int i=n-2; i>=0; i--){
//             int jumps = nums[i];
//             for(int j=1; j<=jumps; j++){
//                 if((i+j) < n){
//                     dp[i] = min(dp[i], dp[i+j] + 1);
//                 }
//             }
//         }
        
//         return dp[0];
//         //return dp[n-1];
//     }
// };