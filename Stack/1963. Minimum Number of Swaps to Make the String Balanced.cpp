

// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/discuss/1746501/C%2B%2B-or-Easy-Understanding-or-Two-Pointer


class Solution {
public:
    int minSwaps(string str) {
        int n = str.length();
        
        int cnt = 0;
        int open = 0, close = 0;
        int j = n-1;
        for(int i=0; i<n; i++){
            char ch = str[i];
            if(ch == '['){
                open++;
            }else if(ch == ']'){
                close++;
            }
            
            if(close > open){
                while(j>=0 && str[j] != '['){
                    j--;
                }
                swap(str[i], str[j]);
                swap(open, close);
                cnt++;
            }
        }
        
        return cnt;
    }
};