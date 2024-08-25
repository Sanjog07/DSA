class Solution {
public:
    int minAddToMakeValid(string str) {
        int n = str.length();
        
        if(n == 0 || n == 1){
            return n;
        }
        
        int cnto = 0, cntc = 0;
        int ans = 0;
        for(int i=0; i<n; i++){
            char ch = str[i];
            if(ch == '('){
                cnto++;
            }else{
                cntc++;
                if(cntc > cnto){
                    ans += 1;
                    cnto++;
                }
            }
        }
        
        if(cnto > cntc){
            return ans + (cnto - cntc);
        }
        
        return ans;
    }
};



/*class Solution {
public:
    int minAddToMakeValid(string str) {
        int n = str.length();
        
        stack<char> s;
        int cnt = 0;
        for(int i=0; i<n; i++){
            char ch = str[i];
            if(ch == '('){
                s.push(ch);
            }else if(ch == ')' && !s.empty()){
                s.pop();
            }else if(ch == ')' && s.empty()){
                cnt++; // i.e ek opening bracket chahiye
            }
        }
        
        if(!s.empty()){
            cnt += s.size();
        }
        
        return cnt;
    }
};*/