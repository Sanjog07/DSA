
//https://www.youtube.com/watch?v=6iE7QJRMXzs


class Solution {
public:
    string decodeAtIndex(string str, int k) {
        int n = str.size();
        string ans = "";
        
        if(k == 1){
            ans += str[0];
            return ans;
        }
        
        long long len = 0;
        for(int i=0; i<n; i++){
            char ch = str[i];
            if(isalpha(ch)){
                len++;
            }else if(isdigit(ch)){
                int f = ch - '0';
                len *= f;
            }
        }
        
        
        for(int i=n-1; i>=0; i--){
            char ch = str[i];
            
            if(isdigit(ch)){
                int f = ch - '0';
                len /= f;
                k %= len;
            }else if(isalpha(ch)){
                if(k == len || k == 0){
                    ans += ch;
                    break;
                }else{
                    len--;
                }
            }
        }
        
        return ans;
    }
};



// THE BELOW 2 METHOD DOESN'T WORK

// class Solution {
// public:
//     string decodeAtIndex(string s, int k) {
//         int n = s.length();
        
//         string ans = "";
//         string str = "";
//         for(int i=0; i<n; i++){
//             char ch = s[i];
//             if(isalpha(ch)){
//                 str += ch;
//                 if(str.size() == k){
//                     //cout<<str<<endl;
//                     ans += str[k-1];
//                     return ans;
//                 }
//             }else if(isdigit(ch)){
//                 int x = ch - '0';
//                 int curr = str.size();
                
//                 int sz = curr*x;
//                 if(sz >= k){
//                     ans += str[k-1-curr];
//                     return ans;
//                 }
//                 string add = str;
//                 for(int j=1; j<x; j++){
//                     str += add;
//                     if(str.size() >= k){
//                         //cout<<str<<endl;
//                         ans += str[k-1];
//                         return ans;
//                     }                    
//                 }
//             }
//         }
        
//         return ans;
//     }
// };




// class Solution {
// public:
//     string decodeAtIndex(string s, int k) {
//         int n = s.length();
        
//         string ans = "";
//         string str = "";
//         for(int i=0; i<n; i++){
//             char ch = s[i];
//             if(isalpha(ch)){
//                 str += ch;
//                 if(str.size() == k){
//                     //cout<<str<<endl;
//                     ans += str[k-1];
//                     return ans;
//                 }
//             }else if(isdigit(ch)){
//                 int x = ch - '0';
//                 string add = str;
//                 for(int j=1; j<x; j++){
//                     str += add;
//                     if(str.size() >= k){
//                         //cout<<str<<endl;
//                         ans += str[k-1];
//                         return ans;
//                     }                    
//                 }
//             }
//         }
        
//         return ans;
//     }
// };