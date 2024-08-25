
// DP se krne ki koi zarurat nhi hai that will take O(n*m)
// use 2-pointer -> O(m)

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty() || s == t){
            return true;
        }
        
        int n = s.length();
        int m = t.length();
        if(n > m){
            return false;
        }
        
        //here we're applying 2-pointer approach
        
        int i=0,j=0;
        while(i < n){
            
            if(j == m){
                return false;
            }
            
            if(s[i] == t[j]){
                i++;
                j++;
            }else{
                j++;
            }
            
        }
        
        return true;
    }
};