

//ISKA KOI EK STANDARD SOLU NHI HAI


class Solution {
public:
    int strStr(string str, string tar) {
        int n = str.size();
        int m = tar.size();
        
        // see eg -> "mississippi" &  "issip"
        // "a" & "a"
        
        int i=0, j=0, st = -1;
        bool prev;
        
        if(n == 1 && m == 1 && str[i] == tar[j]){
            return 0;
        }
        
        if(str[i] == tar[j]){
            j = 1;
            prev = true;
        }else{
            prev = false;
        }
        i = 1;
        
        while(i < n){
            if(str[i] != tar[j]){
                j = 0;
                // if(str[i] == tar[j]){
                //     j++;
                // }
                if(prev == true){
                    i = st+1;
                    st = -1;
                }else{
                    i++;
                }
                
                prev = false;
                
            }else{
                if(st == -1){
                    st = i;
                }
                i++;
                j++;
                if(j == m){
                    return i - m;
                }
                
                prev = true;
            }
        }
        
        return -1;
    }
};





// class Solution {
// public:
//     int strStr(string str, string tar) {
//         if(tar == ""){
//             return 0;
//         }
        
//         int idx = str.find(tar);
        
//         //cout<<idx;
        
//         return idx;
//     }
// };