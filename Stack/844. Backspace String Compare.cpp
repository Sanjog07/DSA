class Solution {
    
    string solve(string str){
        int n = str.size();
        
        string ans = "";
        int hash = 0;
        for(int i=n-1; i>=0; i--){
            char ch = str[i];
            if(ch == '#'){
                hash++;
            }else{
                if(hash == 0){
                    ans += ch;
                }else{
                    hash--;
                }
            }
        }
        
        return ans;
    }
    
public:
    bool backspaceCompare(string s, string t) {
        string ans1 = solve(s);
        string ans2 = solve(t);
        
        return ans1 == ans2;
    }
};




/*class Solution {
    
string solve(string str){
    int n = str.size();
    
    stack<char> s;
    for(int i=0; i<n; i++){
        char ch = str[i];
        if(ch == '#' && !s.empty()){
            s.pop();
        }else if(ch != '#'){
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
    
public:
    bool backspaceCompare(string s, string t) {
        string str1 = solve(s);
        string str2 = solve(t);
        
        return str1 == str2;
    }
};*/