

// RECURSIVE SOLU: https://www.youtube.com/watch?v=yaCRdWMq4A4


// ITERATIVE: https://www.youtube.com/watch?v=CW3ZYAN5Huo


/////////////////   RECURSIVE   ///////////////////

class Solution {
     string helper(string& s,int n,int& i){
        string res = "";
        while(i < n && s[i] != ']'){
            char ch = s[i];
            if(isdigit(ch)){
                int num = 0;
                while(i < n && isdigit(s[i])){
                    num = ((num*10) + (s[i]-'0'));
                    i++;
                }
                
                i++; // to avoid '[' -> as ye res mei aayega hi nhi 
                string ans = helper(s,n,i);
                      
                // now add this chhoti problem ka ans to the res string 
                // num, no of times
                      
                i++;  // to avoid ']' 
                for(int j=1; j<=num; j++){
                    res += ans;
                }
                
            }else{
                res += ch;
                i++;
            }
            
        }
                      
        return res;
    }
    
public:
    string decodeString(string s) {
        int n = s.length();
        
        int i = 0;
        return helper(s,n,i);
    }
};


//////////////   ITERATIVE   /////////////

class Solution {
public:
    string decodeString(string s) {
        int n = s.length();
        
        stack<int> si;
        stack<string> ss;
        
        string res = "";
        int i = 0;
        while(i < n){
            char ch = s[i];
            if(isdigit(ch)){
                int num = 0;
                while(i < n && isdigit(s[i])){
                    num = ((num*10) + (s[i]-'0'));
                    i++;
                } 
                si.push(num);
            }else if(ch == '['){
                ss.push(res);
                res = "";
                i++;
            }else if(ch == ']'){
                string ans = "";
                ans += ss.top();
                ss.pop();
                
                int x = si.top();
                si.pop();
                
                for(int j=1; j<=x; j++){
                    ans += res;
                }
                
                res = ans;
                //ss.push(res);
                i++;
            }else{
                res += ch;
                i++;
            }
        }
        
        return res;
    }
};

