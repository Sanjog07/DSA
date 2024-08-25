
class Solution {
    
    vector<string> ans;
    void solve(int n, string str, int open, int close){
        if(open > n || close > n || close > open){
            return;
        }       
        if(open == n && close == n){
            ans.push_back(str);
            return;
        }        

        solve(n, str + "(", open+1, close);
        solve(n, str + ")", open, close+1);
        
        return;
    }
    
    public:
        vector<string> generateParenthesis(int n) {
            solve(n, "(", 1, 0);

            return ans;
        }
    };    

// // this thing will give wrong ans
// class Solution {
    
//     vector<string> ans;
//     void solve(int n, string str, int open, int close){
//         if(open > n-1 || close > n-1 || close > open){
//             return;
//         }       
//         if(open == n-1 && close == n-1){
//             str += ")";
//             ans.push_back(str);
//             return;
//         }      

//         solve(n, str + "(", open+1, close);
//         solve(n, str + ")", open, close+1);
        
//         return;
//     }
    
// public:
//     vector<string> generateParenthesis(int n) {
//         solve(n, "(", 0, 0);
        
//         return ans;
//     }
// };


    






//class Solution {
 
//     bool isValid(string str) {
//         int n = str.length();
//         if(n == 1){
//             return false;
//         }
        
//         stack<char> s;
//         for(int i=0; i<n; i++){
//             char ch = str[i];
//             if(ch == '(' || ch == '{' || ch == '['){
//                 s.push(ch);
//             }else if(!s.empty()){
//                 char character = s.top();
//                 if(ch == ')' && character != '('){
//                     return false;
//                 }else if(ch == '}' && character != '{'){
//                     return false;
//                 }else if(ch == ']' && character != '['){
//                     return false;
//                 }
                
//                 s.pop();
//             }else{
//                 // i.e the stack is empty -> 
//                 // i.e iss closing bracket ka koi opening 
//                 // bracket hi nhi hai
                
//                 return false;
//             }
//         }
        
//         return s.empty() ? true : false;
//     }    
    
    
//  vector<string> solu;
//  void solve(int x, string s){
//      if(x == 0){
//          s.push_back(')');
//          if(isValid(s)){
//              solu.push_back(s);
//          }
         
//          return;
//      }
     
//      solve(x-1, s + "(");
//      solve(x-1, s + ")");
     
//      return;
//  }   
    
// public:
//     vector<string> generateParenthesis(int n) {
//         int x = 2*n - 2;
        
//         solve(x, "(");
        
//         return solu;
//     }
// };