

// https://leetcode.com/problems/number-of-ways-to-select-buildings/discuss/1907312/Easy-to-Understand-C%2B%2B-Code

// https://leetcode.com/problems/number-of-ways-to-select-buildings/discuss/1907026/Easy-understanding-C%2B%2B-code-with-comments

// https://leetcode.com/problems/number-of-ways-to-select-buildings/discuss/1907233/Idea-Explained-oror-DP-(Memoization)-oror-C%2B%2B-Clean-Code

#define ll long long

class Solution {
public:
    long long numberOfWays(string str) {
        ll n = str.length();
        
        ll cnt0 = 0;
        ll cnt1 = 0;
        for(ll i=0; i<n; i++){
            char ch = str[i];
            if(ch == '0'){
                cnt0++;
            }else{
                cnt1++;
            }
        }
        
        ll count0 = 0;
        ll count1 = 0;
        ll ans = 0;
        for(int i=0; i<n; i++){
            char ch = str[i];
            if(ch == '0'){
                count0++;
                ans += (count1 * (cnt1 - count1));
            }else{
                count1++;
                ans += (count0 * (cnt0 - count0));                
            }
        }
        
        return ans;
    }
};


// #define ll long long

// class Solution {
    
//     ll dp[100002][3][4];
    
//     ll helper(string &str,ll i, ll prev,ll cnt, ll n){
//         if(cnt == 3){
//             return 1;
//         }        
//         if(i >= n){
//             return 0;
//         }

//         if(dp[i][prev][cnt] != -1){
//             return dp[i][prev][cnt];
//         }
        
//         ll ans = 0;
//         ans += helper(str, i+1, prev, cnt, n);
        
//         char ch = str[i];
//         ll val = ch - '0';
//         if(val != prev){
//             ans += helper(str, i+1, val, cnt+1, n);
//         }
        
//         return dp[i][prev][cnt] = ans;
//     }
    
// public:
//     long long numberOfWays(string str) {
//         ll n = str.length();
        
//         // dp[n+1][3][4]; // isko likhne se pta nhi kyu error aa rha hai
//         memset(dp,-1, sizeof(dp));
        
//         ll ans = helper(str,0,2,0,n);
        
//         return ans;
//     }
// };


// Below one is a O(n^2) approach -> Giving TLE



// #define ll long long

// class Solution {
    
//     ll ans = 0;
    
//     void helper(string str, ll s, char prev, ll cnt, ll n){
//         if(cnt == 3){
//             ans++;
//             return;
//         }        
//         if(s >= n){
//             return;
//         }
        
//         for(ll i=s; i<n; i++){
//             char ch = str[i];
//             if(ch == prev){
//                 continue;
//             }
//             helper(str, i+1, ch, cnt+1, n);
//         }
        
//         return;
//     }
    
// public:
//     long long numberOfWays(string str) {
//         ll n = str.length();
        
//         // for(ll i=0; i<n; i++){
//         //     char ch = str[i];
//         //     helper(str, 0, ch, 1, n);
//         // }
        
//         helper(str, 0, 'a', 0, n);
        
//         return ans;
//     }
// };