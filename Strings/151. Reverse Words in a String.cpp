class Solution {
public:
    string reverseWords(string str) {
        int n = str.length();
        
        string res = "";
        string token = "";
        
        vector<string> ans;
        
        for(int i=0; i<n; i++){
            char ch = str[i];
            if(ch == ' '){
                if(token == ""){
                    continue;
                }else{
                    ans.push_back(token);
                    token = "";
                }
            }else{
                token += ch;
            }
        }
        if(token != ""){
            ans.push_back(token);
        }
        
        reverse(ans.begin(), ans.end());
        for(auto s: ans){
            res += (s + " ");
        }
          
        res.pop_back(); //last wala space delete
        return res;
    }
};