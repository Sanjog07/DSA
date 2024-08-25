class Solution {
    
    vector<string> solu;
    unordered_set<string> se;
    void solve(string str,int i,int n, string ans){
        if(i == n){
            ans.pop_back(); // jo last wala space add hoga vo extra
            // hoga, to usse remove kr do
            
            solu.push_back(ans);
            return;
        }
        
        string temp = "";
        for(int j=i; j<n; j++){
            temp += str[j];
            if(se.find(temp) != se.end()){
                solve(str, j+1, n, ans + temp + " ");
            }
        }
        
        return;
    }
    
    
public:
    vector<string> wordBreak(string str, vector<string>& dict) {
        int n = str.length();
        int m = dict.size();
        
        for(int i=0; i<m; i++){
            se.insert(dict[i]);
        }
        
        solve(str,0,n,"");
        
        return solu;
    }
};