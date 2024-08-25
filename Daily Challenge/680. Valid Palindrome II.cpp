class Solution {
    
    bool isPalindrome(string str, int s, int e){
        while(s < e){
            if(str[s] != str[e]){
                return false;
            }
            s++;
            e--;
        }
        return true;
    }
    
public:
    bool validPalindrome(string str) {
        int n = str.length();
        
        int s = 0;
        int e = n-1;
        
        if(isPalindrome(str, s, e)){
            return true;
        }
        
        bool ans;
        while(s < e){
            if(str[s] != str[e]){
                ans = isPalindrome(str, s+1, e) || isPalindrome(str, s, e-1);
                break;
            }
            s++;
            e--;
        }
        
        return ans;
    }
};









// class Solution {
    
//     bool isPalindrone(string str){
//         string s = str;
//         reverse(s.begin(), s.end());
        
//         return str == s;
//     }
    
// public:
//     bool validPalindrome(string str) {
//         int n = str.length();
        
//         if(isPalindrone(str)){
//             return true;
//         }
        
//         int s = 0;
//         int e = n-1;
//         int pvt1 = -1, pvt2 = -1;
        
//         while(s < e){
//             if(str[s] != str[e]){
//                 pvt1 = s;
//                 pvt2 = e;
//                 break;
//             }
//             s++;
//             e--;
//         }
        
//         // i.e hum kya lr rhe hai ki jha pe bhi characters 
//         // unequal aa rhe hai -> hum un dono mei se kisi ek ko 
//         // delete krke dekhenge
        
//         string str1 = "", str2 = "";
        
//         for(int i=0; i<n; i++){
//             if(i != pvt1){
//                 str1 += str[i];
//             }
//             if(i != pvt2){
//                 str2 += str[i];
//             }
//         }
        
//         if(isPalindrone(str1) || isPalindrone(str2)){
//             return true;
//         }
        
//         return false;
//     }
// };



// Ye approch nhi use kr skte -> as ordering bhi matter krti hai yha pe
//see this eg -> "tebbem"

// class Solution {
// public:
//     bool validPalindrome(string str) {
//         int n = str.length();
        
//         unordered_map<char, int> m;
        
//         for(int i=0; i<n; i++){
//             char ch = str[i];
//             m[ch]++;
//         }
        
//         int cnt = 0;
//         for(auto p: m){
//             if(p.second == 1){
//                 cnt++;
//             }
//         }
        
//         if(cnt > 2){
//             return false;
//         }
        
//         return true;
//     }
// };