
// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/discuss/1907028/C%2B%2B-1-linerxorcount-set-bits

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        int mask = 1;
        
        while(start > 0 || goal > 0){
            int x = start&mask;
            int y = goal&mask;
            
            if(x != y){
                cnt++;
            }
            
            start = start >> 1;
            goal = goal >> 1;
        }
        
        return cnt;
    }
};