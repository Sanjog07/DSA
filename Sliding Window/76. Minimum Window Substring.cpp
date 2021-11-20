class Solution {
public:
    string minWindow(string s, string t) {
        //s and t consist of uppercase and lowercase English letters
        int len = s.length();
        int n = t.length();
        
        unordered_map<char,int> mp;
        for(int i=0; i<n; i++){
            mp[t[i]]++;
        }
        
        string ans = "";
        int l=0, r=0;
        
        unordered_map<char,int> m;
        int mcnt = 0; // i.e match count
        
        while(l <= r && r < len){
            // acquire till mcnt < n
            char ch = s[r];
            m[ch]++;
            
            if(m[ch] <= mp[ch] && mcnt < n){
                mcnt++;
            }
            
            
            //collect answers and release till mcnt == n 
            if(mcnt == n){
                while(l <= r && mcnt == n){
                    string pans = s.substr(l, (r-l+1));
                    if(ans.length() == 0 || pans.length() < ans.length()){
                        ans = pans;
                    }
                    
                    char c = s[l];
                    m[c]--;
                    
                    if(m[c] < mp[c]){
                        mcnt--;
                    }
                    
                    l++;
                }
            }
            
            r++;
        }
        
       return ans;
    }
};