
//SOLUTION LINK: https://leetcode.com/problems/k-th-symbol-in-grammar/discuss/1645472/C%2B%2B-Sol-or-Faster-or-Efficient-or-Easy-Intuition-cpp-recursion

class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1){
            return 0;
        }
        
        int x = ceil(k/2.0);
        int back = kthGrammar(n-1, x);
        
        if(k%2 == 0){
            return !back;
        }
        
        return back;
        
        // neeche ek aur solu bhi hai which was giving TLE
        // usmei nth row as string nikali thi 
        // by observing some pattern
        
    }
};


// iss wale solu mei TLE aa rhi hai, as hum hr recursive 
// call mei substr nikaal rhe hai 
// as substr takes O(n)
// so overall T.C = O(n^2)

// class Solution {
    
//     string helper(int n){
    
//       
    
//         if(n == 1){
//             return "0";
//         }
//         if(n == 2){
//             return "01";
//         }
        
//         string s = helper(n-1);
//         string ans = "";
//         ans += s;
        
//         int x = s.size();
//         int i = x/2;
        
//         string left = s.substr(0,i);
//         string right = s.substr(i); 
        
//         ans += right;
//         ans += left;
        
//         return ans;
//     }
    
// public:
//     int kthGrammar(int n, int k) {
//         string str = helper(n);
        
//         char ch = str[k-1];
        
//         int solu = ch - '0';
        
//         return solu;
        
        
//     }
// };