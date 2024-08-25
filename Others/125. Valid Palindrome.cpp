class Solution {
public:
    bool isPalindrome(string str) {
        int n = str.length();
        
        string ans = "";
        for(int i=0; i<n; i++){
            char ch = str[i];
            if(isalnum(ch)){
                ans += tolower(ch);
            }
        }
        
        cout<<ans;
        
        string temp = ans;
        reverse(temp.begin(), temp.end());
        
        return temp == ans;
    }
};