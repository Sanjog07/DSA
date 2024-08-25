#define mod 1003
#define ll long long


class Solution{
    
    unordered_map<string,int> dp;
    int solve(int s,int e,bool istrue, string &str){
        if(s > e){
            return 0;
        }
        if(s == e){
            if(istrue == true && str[s] == 'T' || istrue == false && str[s] == 'F'){
                return 1;
            }
            
            return 0;
        }
        string temp = "";
        temp += to_string(s);
        temp += to_string(e);
        temp += to_string(istrue);
        
        if(dp.find(temp) != dp.end()){
            return dp[temp];
        }
        
        int ans = 0;
        for(int k=s+1; k<=e-1; k+=2){
            
            int lt = solve(s,k-1,true,str)%mod;
            int lf = solve(s,k-1,false,str)%mod;
            int rt = solve(k+1,e,true,str)%mod;
            int rf = solve(k+1,e,false,str)%mod;
            
            
            char ch = str[k];
            int val; 
            if(ch == '&'){
                if(istrue){
                    val = (lt * rt)%mod;
                }else{
                    val = ((lf * rt)%mod + (lt * rf)%mod + (lf * rf)%mod);
                }
            }else if(ch == '|'){
                 if(istrue){
                    val = ((lt * rt)%mod + (lt * rf)%mod + (lf * rt)%mod);
                }else{
                    val = ((lf * rf)%mod);
                }               
            }else{
                if(istrue){
                    val = ((lf * rt)%mod + (lt * rf)%mod);
                }else{
                    val = ((lf * rf)%mod + (lt * rt)%mod);
                }                
            }
            
            ans = (ans%mod + val%mod)%mod;
        }
        
        return dp[temp] = ans;
    }
    
public:
    int countWays(int n, string str){
        int res = solve(0,n-1,true,str);
        
        return res;
    }
};