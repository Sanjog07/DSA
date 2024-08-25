

//  BRUTE FORCE APPROACH SE HI ANS AAYEGA
// I.E SABHI SUBSEQUENCES NIKAAALO AND UN MEI SE JO JO
// PALINDROMIC HAI UNHE MAP MEI STORE KR LO


class Solution {
    
    bool isPalindrome(string s){
        string x = s;
        reverse(x.begin(), x.end());
        
        return s == x;
    }
    
public:
    int maxProduct(string s) {
        int n = s.length();
        
        unordered_map<int,int> m;
        
        for(int mask = 1; mask < (1 << n); mask++){
            
            string str;
            for(int i=0; i<n; i++){
                if(mask & (1<<i)){
                    str += s[i];
                }
            }
            
            if(isPalindrome(str)){
                m[mask] = str.length();
            }
        }
        
        int ans = INT_MIN;
        for(auto a: m){
            for(auto b: m){
                if(((a.first) & (b.first)) == 0){
                    // it means ki dono subsequences disjoint hai
                    ans = max(ans, (a.second * b.second));
                }
            }
        }
        
        return ans;
    }
};