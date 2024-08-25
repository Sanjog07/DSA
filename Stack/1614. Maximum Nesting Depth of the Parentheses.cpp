
#include<bits/stdc++.h>
using namespace std;


// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/discuss/1746663/C%2B%2B-oror-TC%3A-O(n)-and-SC%3A-O(1)-oror
// YE UPAR WALA SOLU AUR JYADA OPTIMIZED HAI


class Solution {
public:
    int maxDepth(string str) {
        int n = str.length();
        if(n == 1){
            return 0;
        }
        
        int ans = 0;
        int cnto = 0;
        for(int i=0; i<n; i++){
            char ch = str[i];
            if(ch == '('){
                cnto++;
                ans = max(ans, cnto);
            }else if(ch == ')') {
                cnto--;
            }
        }
        
        return ans;
    }
};



// class Solution {
    
//     int max(int a,int b){
//         if(a > b){
//             return a;
//         }
        
//         return b;
//     }
    
// public:
//     int maxDepth(string str) {
        
//         // input string to valid hi hogi ye to given hai
//         // so jitne ek time mei max opening brackets honge
//         // utni hi depth hogi
//         // as given string pehle se hi valid hai 
//         // to closing brackets ki dikkat lene ki koi zarurat nhi hai
//         // vo hongi hi
        
//         int n = str.length();
//         if(n == 0){
//             return 0;
//         }
//         if(n == 1 && (str[0] != '(' || str[0] != ')')){
//             return 0;
//         }
        
//         int ans = 0;
//         stack<char> s;
//         for(int i=0; i<n; i++){
//             char ch = str[i];
//             if(ch == '('){
//                 s.push(ch);
//                 ans = max(ans, s.size());
//             }else if(ch == ')' && !s.empty()){
//                 s.pop();
//             }
//         }
        
//         return ans;
//     }
// };