

//https://www.youtube.com/watch?v=Z4Af1_t7wzk

class Solution {
public:
    int compareVersion(string a, string b) {
        int n = a.size();
        int m = b.size();
        
        int i=0, j=0;
        
        while(i < n || j < m){
            string x = "0", y = "0";
            // inko 0 isliye liya hai bcz jb ek string khatam
            // ho jayegi and dusri nhi tb empty wali ki value
            // will be 0
            
            while(i < n && a[i] != '.'){
                x += a[i];
                i++;
            }
            
            while(j < m && b[j] != '.'){
                y += b[j];
                j++;
            }   
            
            int no1 = stoi(x);
            int no2 = stoi(y);
            
            if(no1 > no2){
                return 1;
            }else if(no1 < no2){
                return -1;
            }
            
            i++; // upar wale while loops hume . pe layege
            j++; // so usse aage jane ke liye ye i++ and j++
        }
        
        return 0;
    }
};



// Bina stoi() ka use kiye 
class Solution {
public:
    int compareVersion(string v1, string v2) {
        int i = 0, j = 0, v1Len = v1.size(), v2Len = v2.size(), n1, n2;
        while (i < v1Len || j < v2Len) {
            n1 = 0;
            n2 = 0;
            while (i < v1Len && v1[i] != '.') {
                n1 = n1 * 10 + (v1[i] - '0'); '4' - '0' = 4 
                i++;
            }
            while (j < v2Len && v2[j] != '.') {
                n2 = n2 * 10 + (v2[j] - '0');
                j++;
            }    
            if (n1 < n2) return -1;
            else if (n1 > n2) return 1;
            i++;
            j++;
        }
        return 0;
    }
};