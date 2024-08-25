
// https://www.youtube.com/watch?v=qtVh-XEpsJo

// O(n)

// // NOTEBOOK

class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int n = str.size();
        
        vector<int> prev(256, -1);
        int ans = INT_MIN;
        
        int i=0, j=0;
        while(j < n){
            char ch = str[j];
            if(prev[int(ch)] == -1){
                prev[int(ch)] = j;
            }else{
                i = max(i, prev[int(ch)] + 1);
                prev[int(ch)] = j;
            }
            
            ans = max(ans, (j-i+1));
            j++;
        }
        
        return (ans == INT_MIN) ? 0 : ans;
    }
};


 // O(2*n) -> why ?
// see eg -> "abcdefgg"
// NOTEBOOK

// class Solution {
// public:
//     int lengthOfLongestSubstring(string str) {
//         int n = str.length();
//         int len = INT_MIN;
        
//         unordered_map<int,int> m;
//         int l=0, r=0;
        
//         while(l <= r && r < n){
//             char ch = str[r];
//             m[ch]++;
            
//             if(m[ch] == 2){
//                 len = max(len, (r-l));
//                 while(m[ch] > 1 && l <= r){
//                     char c = str[l];
//                     // if(m[c] == 1){
//                     //     m.erase(c);
//                     // }else{
//                     //     m[c]--;
//                     // }
//                     m[c]--; // upar wali condi ki jagha sirf itna bhi likh 
//                             // skte hai
                    
//                     l++;
//                 }
//             }
            
//             r++;
//         }
        
//         // for cases like "abcdefghijk" -> yha pe kisi bhi character ki freq         2 ho hi nhi // kisi bhi character ki freq 2 ho hi nhi
        
//         // and for "abcabcbde" -> ismei last wali substring is the longest 
//         // so loop khatam hone ke baad ans calculate krna pdega
//         len = max(len, (r-l));
        
        
//         if(len == INT_MIN){
//             return 0;
//         }
        
//         return len;
        
//     }
// };