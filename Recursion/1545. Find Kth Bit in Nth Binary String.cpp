class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1){
            return '0';
        }
        
        int x = (1<<n);
        if(k >= 1 && k < x/2){
            return findKthBit(n-1,k);
        }else if(k == x/2){
            return '1';
        }
        
        int y = (x-k);
        char ch = findKthBit(n-1,y);
        if(ch == '0'){
            return '1';
        }
        return '0';
    }
};