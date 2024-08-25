class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;
        
        while(a > 0 || b > 0 || c > 0){
            int x = (a & 1);
            int y = (b & 1);
            int z = (c & 1);
            
            if(z == 1 && x == 0 && y == 0){
                cnt++;
            }else if(z == 0){
                if((x == 1 && y == 0) || (y == 1 && x == 0)){
                    cnt++;
                }else if(x == 1 && y == 1){
                    cnt += 2;
                }
            }
            
            a = a >> 1;
            b = b >> 1;
            c = c >> 1;
            
        }
        
        return cnt;
    }
};