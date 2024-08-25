
// String find() method will not work in this ques
// bcz String find() method finds the first occurence 
// of a sub-string -> "applepenapple" , ["apple","pen"] -> to iss wale 
// ka ans nhi aayega iss method se



// https://www.youtube.com/watch?v=_iIK7Gu7MNo
// Rather than finding substring in each loop
// we can set a starting pt of the string
class Solution {
    
    unordered_set<string> m;
    int dp[302];
    bool solve(string s,int n,int i){
        if(i == n){
            return true;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        
        string temp = "";
        for(int j=i; j<n; j++){
            temp += s[j];
            
            if(m.find(temp) != m.end()){
                if(solve(s,n,j+1)){
                    return dp[i] = 1;
                }
            }
        }
        
        return dp[i] = 0;
    }
    
public:
    bool wordBreak(string s, vector<string>& dict) {
        int n = s.length();
        int d = dict.size();
        
        for(int i=0; i<d; i++){
            m.insert(dict[i]);
        }
        
        dp[n];
        memset(dp, -1, sizeof dp);
        
        return solve(s,n,0);
    }
};




// class Solution{
    
//     unordered_map<string,int> dp;
    
//     int helper(string s, vector<string>& dict,int n,int m){
//         if(s.empty()){
//             return 1;
//         }
//         if(dp[s] != 0){
//             return dp[s];
//         }
        
//         unordered_set<string> se;
//         for(int i=0; i<n; i++){
//             se.insert(dict[i]);
//         }
        
//         for(int i=1; i<=m; i++){
//             string x = s.substr(0,i);
            
//             //for(int j=0; j<n; j++){
//                 if(se.find(x) != se.end()) {
//                     string y = s.substr(i);
//                     if(wordBreak(y,dict)){
//                         return dp[s] = 1;
//                     }
//                 }
//             //}
//         }
        
//         return dp[s] = -1;        
//     }
    
// public:
//     bool wordBreak(string s, vector<string>& dict) { 
//         int n = dict.size();
//         int m = s.length();
        
//         if(helper(s,dict,n,m) == 1){
//             return true;
//         }
//         return false;
//     }
// };