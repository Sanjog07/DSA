class Solution {
public:
    string minRemoveToMakeValid(string str) {
        int n = str.length();
        
        // ismei dhyaan rkhna 2 cases ho skte hai
        // ya to no of closing brackets jyada ho 
        // ya fir no of opening brackets jyada ho
        
        int open = 0;
        
        string ans = "";
        
        for(int i=0; i<n; i++){
            char ch = str[i];
            if(ch == '('){
                open++;
            }else if(ch == ')'){
                if(open == 0){
                    continue;
                }else{
                    open--;
                }
            }
            
            ans += ch;
        }
        
        // if open > 0 , then remove last open no of 
        // opening brackets from ans
        if(open == 0){
            return ans;
        }
        
        string solu = "";
        for(int i=ans.size()-1; i>=0; i--){
            char ch = ans[i];
            if(ch == '(' && open != 0){
                open--;
                continue;
            }
            solu += ch;
        }
        
        reverse(solu.begin(),solu.end());
        return solu;
    }
};


// class Solution {
// public:
//     string minRemoveToMakeValid(string str) {
//         int n = str.length();
        
//         int open = 0, close = 0;
        
//         string ans = "";
        
//         for(int i=0; i<n; i++){
//             char ch = str[i];
//             if(ch == '('){
//                 open++;
//             }else if(ch == ')'){
//                 close++;
//                 if(close > open){
//                     close -= 1;
//                     continue;
//                 }
//             }
            
//             ans += ch;
//         }
        
//         return open != close ? "" : ans;
        
//     }
// };