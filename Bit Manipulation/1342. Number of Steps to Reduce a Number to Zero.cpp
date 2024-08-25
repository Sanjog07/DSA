class Solution {
public:
    int numberOfSteps(int n) {
        int cnt = 0;
        while(n > 0){
            if((n&1) == 0){
                n /= 2;
            }else{
                n -= 1;
            }
            
            cnt++;
        }
        
        return cnt;
    }
};