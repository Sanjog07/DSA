class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(26, 0);
        
        // jb t mei extra characters honge tb ye galat ans dega
//         for(int i=0; i<s.length(); i++){
//             char ch = s[i];
//             freq[ch - 'a']++;
//         }
        
//         for(int i=0; i<t.length(); i++){
//             char ch = t[i];
//             freq[ch - 'a']--;
//         } 
        
        
    //so bss itna krna hai ki t ke charac. ko array mei store kro
        for(int i=0; i<t.length(); i++){
            char ch = t[i];
            freq[ch - 'a']++;
        }
        
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            freq[ch - 'a']--;
        }        
        
        for(int i=0; i<26; i++){
            if(freq[i] != 0){
                return false;
            }
        }
        
        return true;
    }
};