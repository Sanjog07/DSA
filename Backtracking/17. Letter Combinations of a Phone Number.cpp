
// Recursion hi hai main to backtracking ki tarah dikh skta hai

class Solution {
    
    string use[10] = {"","", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> ans;
    void helper(int i,string dig, string asf, int n){
        if(i > n){
            return;
        }
        if(asf.length() == n){ // i.e i == n
            ans.push_back(asf);
            return;
        }
        
        char c = dig[i];
        int idx = c - '0';
        
        string str = use[idx];
        for(int j=0; j<str.size(); j++){
            char ch = str[j];
            helper(i+1, dig, asf + ch, n);
        }
        
        
        // isko backtracking jaisa dikhane ke liye hum aise likh skte hai
        // for(int j=0; j<str.size(); j++){
        //     char ch = str[j];
        //     asf.push_back(ch);
        //     helper(i+1, dig, asf, n);
        //     asf.pop_back();
        // }     
        
        return;
    }
    
public:
    vector<string> letterCombinations(string dig) {
        int n = dig.length();
        if(n == 0){
            return {};
        }
        
        helper(0, dig, "", n);
        
        return ans;
    }
};