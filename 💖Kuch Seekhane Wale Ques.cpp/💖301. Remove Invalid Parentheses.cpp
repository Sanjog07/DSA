

// https://www.youtube.com/watch?v=Cbbf5qe5stw
// thoda idea iss video se hai
// but duplicates remove krne wala idea hmara hai
// video mei set use kiya hua hai

class Solution {
    
//     bool isValid(string str){
//         int n = str.length();
        
//         int cnt = 0;
//         for(int i=0; i<n; i++){
//             char ch = str[i];
//             if(ch == '('){
//                 cnt++;
//             }else if(ch == ')'){
//                 cnt--;
//                 if(cnt < 0){
//                     return false;
//                 }
//             }
//         }
        
//         if(cnt > 0){
//             return false;
//         }
        
//         return true;
//     }
    
    int cntInvalidChar(string str){
        int n = str.length();
        
        int open = 0, close = 0;
        for(int i=0; i<n; i++){
            char ch = str[i];
            if(ch == '('){
                open++;
            }else if(ch == ')'){
                if(open > 0){
                    open--;
                }else{
                    close++;
                }
            }
        }
        
        return open + close;
    }
    
    vector<string> ans;
    
    
    // ISS WALE SOLVE SE DUPLICATES REMOVE NHI HO RHE THE
    // TO DUPLICATES REMOVE KRNE KE LIYE SET YA MAP KA USE KRNA PDTA
    // see this eg -> ")(f"
    
//     void solve(string str,int len){
//         if(str.length() < len){
//             return;
//         }
//         if(str.length() == len && isValid(str)){
//             ans.push_back(str);
//             return;
//         }
        
//         int n = str.length();
//         for(int i=0; i<n; i++){
//             if(i != 0 && str[i] == str[i-1]){
//                 continue;
//             }
//             string nstr = str.substr(0,i) + str.substr(i+1);
//             solve(nstr, len);
//         }
        
//         return;
//     }
    
    
    // YE UPAR WALE SE THODA OPTIMIZED HAI
    // ISMEI DUPLICATES REMOVE HO GYE
    
//     void solve(int s,string str,int len){
    
        // upar wale solve() ke comparatively ye wala part change hua hai
//         if(str.length() == len){
//             if(isValid(str)){
//                 ans.push_back(str);
//             }
//             return;
//         }
        
//         int n = str.length();
    
        // upar wale solve() ke comparatively ye wala part change hua hai
//         for(int i=s; i<n; i++){
//             if(i != s && str[i] == str[i-1]){
//                 continue;
//             }
//             string nstr = str.substr(0,i) + str.substr(i+1);
            
//             // 
//             solve(i, nstr, len);
//         }
        
//         return;
//     } 
    
    
    // YE UPAR WALE SE THODA AUR OPTIMIZED HAI
    // ISMEI ISVALID KA USE NHI KR RHE
    
    void solve(int s,string str,int len){
        if(str.length() == len){
            if(cntInvalidChar(str) == 0){
                ans.push_back(str);
            }
            return;
        }
        
        int n = str.length();
        for(int i=s; i<n; i++){
            if(i != s && str[i] == str[i-1]){
                continue;
            }
            string nstr = str.substr(0,i) + str.substr(i+1);
            
            // why hum i == 0 se nhi s se start kr rhe hai
            // bcz iss loop mei hum ek hi character remove kr rhe hai
            // and agli string will be of length, 1 less than current
            // so usko 0 se iterate krenge firse i.e starting se iterate
            // krenge -> but hum vo starting wale characters to already
            // pichli iteartions mei check kr chuke honge
            // and agr ab dobara krenge to duplicates generate honge.
            solve(i, nstr, len);
        }
        
        return;
    }    
    
public:
    vector<string> removeInvalidParentheses(string s) {
        int n = s.length();
        int cnt = cntInvalidChar(s);
        if(cnt == n){
            return {""};
        }
        
        int len = n - cnt;
        
        //solve(s,len);
        solve(0,s,len);
        
        return ans;
    }
};