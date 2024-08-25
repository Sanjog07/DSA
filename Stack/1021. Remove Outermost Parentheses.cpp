class Solution {
public:
    string removeOuterParentheses(string str) {
        int n = str.length();
        
        int cnt = 0;
        string temp = "";
        
        string ans = "";
        for(int i=0; i<n; i++){
            char ch = str[i];
            temp += ch;
            if(ch == '('){
                cnt++;
            }else{
                cnt--;
                if(cnt == 0){
                    ans += temp.substr(1, temp.size()-2);
                    temp = "";
                }
            }
        }
        
        return ans;
    }
};




/*class Solution {
public:
    string removeOuterParentheses(string str) {
        int n = str.length();
        
        string ans = "";
        string temp = "";
        
        stack<char> s;
        for(int i=0; i<n; i++){
            char ch = str[i];
            temp += ch;
            if(ch == '('){
                s.push(ch);
            }else if(ch == ')' && !s.empty()){
                s.pop();
                if(s.empty()){
                    ans += temp.substr(1, temp.size()-2);
                    temp = "";
                }
            }
        }
        
        return ans; 
    }
};*/