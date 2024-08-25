
class Solution {
public:
    bool isValid(string str) {
        int n = str.length();
        if(n == 1){
            return false;
        }
        
        stack<char> s;
        for(int i=0; i<n; i++){
            char ch = str[i];
            if(ch == '(' || ch == '{' || ch == '['){
                s.push(ch);
            }else if(!s.empty()){
                char character = s.top();
                if(ch == ')' && character != '('){
                    return false;
                }else if(ch == '}' && character != '{'){
                    return false;
                }else if(ch == ']' && character != '['){
                    return false;
                }
                
                s.pop();
            }else{
                // i.e the stack is empty -> 
                // i.e iss closing bracket ka koi opening 
                // bracket hi nhi hai
                
                return false;
            }
        }
        
        return s.empty() ? true : false;
    }
};


class Solution {
public:
    bool isValid(string s) {
        
        // this method will work up to a limit
        // won't work for -> "{(})"
        
        int n = s.length();
        if(n == 1){
            return false;
        }
        
        int cnt1o = 0;
        int cnt1c = 0;
        int cnt2o = 0;
        int cnt2c = 0;
        int cnt3o = 0;
        int cnt3c = 0;   
        
        for(int i=0; i<n; i++){
            char ch = s[i];
            if(ch == '('){
                cnt1o++;
            }else if(ch == '{'){
                cnt2o++;
            }else if(ch == '['){
                cnt3o++;
            }else if(ch == ')'){
                cnt1c++;
                if(cnt1c > cnt1o){
                    return false;
                }
            }else if(ch == '}'){
                cnt2c++;
                if(cnt2c > cnt2o){
                    return false;
                }                
            }else if(ch == ']'){
                cnt3c++;
                if(cnt3c > cnt3o){
                    return false;
                }                
            }
        }
        
        if(cnt1o == cnt1c && cnt2o == cnt2c && cnt3o == cnt3c){
            return true;
        }
        
        return false;
    }
};




