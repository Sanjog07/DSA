class Solution {
public:
    string removeDuplicates(string str) {
        int n = str.length();
        
        stack<char> s;
        s.push(str[0]);
        for(int i=1; i<n; i++){
            char ch = str[i];
            if(!s.empty() && s.top() == ch){
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