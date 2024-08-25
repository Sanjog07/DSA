class Solution {
public:
    string makeGood(string str) {
        int n = str.length();
        if(n == 0 || n == 1){
            return str;
        }
        
        stack<char> s;
        s.push(str[0]);
        
        for(int i=1; i<n; i++){
            char ch = str[i];
            
            if((!s.empty()) && ((int(ch) > int(s.top())) || (int(ch) < int(s.top()))) && (tolower(ch) == tolower(s.top()))){
                s.pop();
            }else{
                s.push(ch);
            }
        }
        
        string ans = "";
        while(!s.empty()){
            ans += s.top();
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};