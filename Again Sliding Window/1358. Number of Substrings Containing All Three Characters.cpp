class Solution {
public:
    int numberOfSubstrings(string str) {
        int n = str.size();
        
        vector<int> freq(3, 0);
        int i = 0 , j = 0;
        
        while(j < n){
            char ch = str[j];
            freq[ch - 'a']++;
            
            if(freq[0] >= 1 && freq[1] >= 1 && freq[2] >= 1){
                break;
            }
            j++;
        }
        
        if(j >= n){
            return 0;
        }
        
        int cnt = (n-j);
        while(j < n){
            char ch = str[i];
            i++;
            
            freq[ch - 'a']--;
            
            if(freq[0] < 1 || freq[1] < 1 || freq[2] < 1 || (j-i+1) < 3){
                while(j < n && (freq[0] < 1 || freq[1] < 1 || freq[2] < 1)){
                    j++;
                    if(j == n){
                        break;
                    }                    
                    char temp = str[j];
                    freq[temp - 'a']++;
                }
            }
            
            if(j < n){
                cnt += (n-j);
            }                   
        }
        
         return cnt;
    }
};