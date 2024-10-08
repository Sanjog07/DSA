
// https://leetcode.com/problems/integer-to-roman/discuss/2053068/simple-array-c%2B%2B-solution


class Solution {
    
public:
    string intToRoman(int num) {
        
        int val[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        
        string roman[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string ans = "";
        for(int i=0; i<13; i++){
            int value = val[i];
            
            while(num >= value){
                ans += roman[i];
                num -= value;
            }
        }
        
        return ans;
    }
};