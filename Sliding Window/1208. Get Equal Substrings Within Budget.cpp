class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        
        if(s == t){
            return n;
        }
        
        int cost = maxCost;
        int ans = INT_MIN;
        
        int l=0, r=0;
        while(l <= r && r < n){
            cost -= abs(int(s[r]) - int(t[r]));
            
            if(cost <= 0){
                if(cost == 0){
                    //consider the current character
                    ans = max(ans, (r-l+1));
                    
                    while(cost < 0 && l <= r){
                        cost += abs(int(s[l]) - int(t[l]));
                        l++;
                    }
                    
                }else if(cost < 0){
                    //don't consider the current character
                    ans = max(ans, (r-l));
                    
                    while(cost < 0 && l <= r){
                        cost += abs(int(s[l]) - int(t[l]));
                        l++;
                    }
                }
                
                
                // ye absolute diff hai
                /// 0 1 2  3  4 5 6 7  8  9 10 11 12 13 14
                /// 3 6 15 11 3 9 8 15 22 10 3 7  3  4  0 
                
                
            }
            
            r++;
        }
        
        // ye last wali subarray ke liye
        ans = max(ans, (r-l));
        
        if(ans == INT_MIN){
            return n;
        }
        return ans;
        
        
        // ans 0 wala case apne aap handle ho jayega
        // e.g:  "anbc"   "vfdg"  0
        // jha koi character same na ho
        // and maxCost = 0
    }
};




