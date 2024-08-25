class Solution {
public:
    int myAtoi(string str) {
        int n = str.size();
        
        long long int num = 0;
        bool neg = false;
        
        int s = 0;
        while(str[s] == ' '){
            s++;
        }
        
        char ch = str[s];
        if(!isdigit(ch)){
            if(ch == '-'){
                neg = true;
            }else if(ch == '+'){
                neg = false;
            }else{
                return 0;
            }
            s++;
        }
        
        for(int i=s; i<n; i++){
            ch = str[i];
            if(isdigit(ch)){
                num = ((num*10) + (ch - '0'));
                if(!neg && num > INT_MAX){
                    return INT_MAX;
                }else if(neg && (-1*num) < INT_MIN){
                    return INT_MIN;
                }
            }else{
                break;
            }
        }
        
        if(neg){
            num *= -1;
        }
        
        return (int)num;
    }
};