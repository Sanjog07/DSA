class Solution {
public:
    int romanToInt(string str) {
        int n = str.length();
        
        unordered_map<char,int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        // m["IV"] = 4;
        // m["IX"] = 9;
        // m["XL"] = 40;
        // m["XC"] = 90;
        // m["CD"] = 400;
        // m["CM"] = 900;
        
        int prev = INT_MIN;
        int num = 0;
        
        for(int i=n-1; i>=0; i--){
            char ch = str[i];
            int val = m[ch];
            if(val < prev){
                num -= val;
            }else{
                num += val;
            }
            
            prev = val;
            
        }
        
        return num;
    }
};