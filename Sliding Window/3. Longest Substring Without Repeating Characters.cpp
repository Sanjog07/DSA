class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int n = str.length();
        int len = INT_MIN;
        
        unordered_map<int,int> m;
        int l=0, r=0;
        
        while(l <= r && r < n){
            char ch = str[r];
            m[ch]++;
            
            if(m[ch] == 2){
                len = max(len, (r-l));
                while(m[ch] > 1 && l <= r){
                    char c = str[l];
                    // if(m[c] == 1){
                    //     m.erase(c);
                    // }else{
                    //     m[c]--;
                    // }
                    m[c]--; // upar wali condi ki jagha sirf itna bhi likh 
                            // skte hai
                    
                    l++;
                }
            }
            
            r++;
        }
        
        // for cases like "abcdefghijk" -> yha pe kisi bhi character ki freq         2 ho hi nhi // kisi bhi character ki freq 2 ho hi nhi
        
        // and for "abcabcbde" -> ismei last wali substring is the longest 
        // so loop khatam hone ke baad ans calculate krna pdega
        len = max(len, (r-l));
        
        
        if(len == INT_MIN){
            return 0;
        }
        
        return len;
        
    }
};