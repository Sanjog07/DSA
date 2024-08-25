class Solution {
public:
    int firstUniqChar(string str) {
        int n = str.length();
        
        unordered_map<int,int> m;
        for(int i=0; i<n; i++){
            char ch = str[i];
            m[ch]++;
        }
        
        for(int i=0; i<n; i++){
            char ch = str[i];
            if(m[ch] == 1){
                return i;
            }
        }
        
        return -1;
    }
};