

class Solution {
    
    vector<string> res;
    
    void helper(int i, string &str, string ans, int dots, int n){
        if(dots == 4){
            if(i == n){
                ans.pop_back();
                res.push_back(ans);
            }
            return;
        }
        if(i >= n){
            return;
        }        
        
        string s = "";
        
        for(int j=i; j<(i+3) && j<n; j++){
            if(s == "0"){
                // i.e iss ye wali 0 leading 0 hogi to break krdo
                break;
            }
            char ch = str[j];
            s += ch;
            
            int val = stoi(s);
            if(val >= 0 && val <= 255){
                helper(j+1, str, ans + s + '.', dots + 1, n);
            }else{
                break;
            }
        }
        
        return;
    }
    
public:
    vector<string> restoreIpAddresses(string str) {
        int n = str.length();
        
        if(n < 4 || n > 12){
            return {};
        }
        
        helper(0, str, "", 0, n);
        
        return res;
    }
};