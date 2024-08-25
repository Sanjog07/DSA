class Solution {
public:
    int equalSubstring(string str, string t, int mc) {
        int n = str.size();
        
        int i = 0, j = 0;
        
        int ans = 0;
        while(j < n){
            int c = abs(t[j] - str[j]);
            mc -= c;
            
            while(i <= j && mc < 0){
                mc += abs(t[i] - str[i]);
                i++;
            }
            
            ans = max(ans, (j-i+1));
            j++;
        }
        
        return ans;
    }
};