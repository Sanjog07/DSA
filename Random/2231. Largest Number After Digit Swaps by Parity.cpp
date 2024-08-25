
// see notebook

class Solution {
public:
    int largestInteger(int num) {
        if(num >= 1 && num <= 9){
            return num;
        }
        
        priority_queue<int, vector<int>, greater<int>> odd;
        priority_queue<int, vector<int>, greater<int>> even;
        
        int temp = num;
        
        while(temp > 0){
            int x = temp % 10;
            temp /= 10;
            
            if((x&1)){
                odd.push(x);
            }else{
                even.push(x);
            }
        }
        
        temp = num;
        int ans = 0;
        long long int p = 1;
        
        while(temp > 0){
            int x = temp % 10;
            temp /= 10;    
        
            if((x&1)){
                int y = odd.top();
                odd.pop();
                ans += y*p;
            }else{
                int y = even.top();
                even.pop();
                ans += y*p;                
            }
            
            p *= 10;
        }
        
        return ans;
    }
};