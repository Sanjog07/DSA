class Solution {
    
    string solve(string str, int k,int n){
        string temp = str;
        
        while(temp.length() > k){
            int sum = 0;
            int cnt = 0;
            string nstr = "";
            
            int i = 0;
            while(i < temp.length()){
                char ch = temp[i];
                cnt++;
                sum += (ch - '0');
                
                if(cnt == k){
                    nstr += to_string(sum);
                    cnt = 0;
                    sum = 0;
                } 
                
                i++;
            }
            
            if(cnt != 0){
                nstr += to_string(sum);
            }
            
            // cout<<nstr<<endl;
            temp = nstr;
        }
        
        return temp;
    }
    
public:
    string digitSum(string str, int k) {
        int n = str.length();
        
        return solve(str, k, n);
    }
};





// class Solution {
    
//     string ans = "";
    
//     void solve(string str, int k){
//         if(str.length() <= k){
//             ans = str;
//             return;
//         }
        
//         string pass = "";
        
//         int i = 0;
//         while(i < str.length()){
//             int sum = 0;
//             int j;
//             for(j=i; j<k+i && j<str.length(); j++){
//                 sum += (str[j] - '0');
//             }
            
//             pass += to_string(sum);
//             i = j;
//         }
        
//         //cout<<pass<<endl;
//         solve(pass, k);
        
//         return;
//     }
    
// public:
//     string digitSum(string s, int k) {
//         solve(s, k);
        
//         return ans;
//     }
// };