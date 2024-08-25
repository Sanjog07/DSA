#define mod 1003
#define ll long long


// Bottom-Up method -> pepcoding
// https://www.youtube.com/watch?v=JbRsM2X2_pg

class Solution{
    
    int solve(string x,string y,int a,int b){
        int dpt[a][a]; // true wali dp
        memset(dpt, 0, sizeof dpt);
        
        int dpf[a][a]; // false wali dp
        memset(dpf, 0, sizeof dpf);
        
        for(int gap=0; gap<a; gap++){
            for(int i=0, j=gap; j<a; i++, j++){
                if(gap == 0){
                    if(x[i] == 'T'){
                        dpt[i][j] = 1;
                        dpf[i][j] = 0;
                    }else if(x[i] == 'F'){
                        dpt[i][j] = 0;
                        dpf[i][j] = 1;                        
                    }
                }else{
                    
                    int val1 = 0, val2 = 0;

                    for(int k=i; k<j; k++){
                        int lt = dpt[i][k];
                        int rt = dpt[k+1][j];
                        int lf = dpf[i][k];
                        int rf = dpf[k+1][j];
                        
                        char ch = y[k];
                        
                        if(ch == '|'){
                            val1 += ((lt*rt)%mod + (lt*rf)%mod + (lf*rt)%mod)%mod;
                            val2 += ((lf*rf)%mod)%mod;
                        }else if(ch == '&'){
                            val1 += ((lt*rt)%mod)%mod;
                            val2 += ((lf*rf)%mod + (lt*rf)%mod + (lf*rt)%mod)%mod;
                        }else if(ch == '^'){
                            val1 += ((lt*rf)%mod + (lf*rt)%mod)%mod;
                            val2 += ((lt*rt)%mod + (lf*rf)%mod)%mod;
                        }
                    }
                    
                    dpt[i][j] = val1%mod;
                    dpf[i][j] = val2%mod;
                }
            }
        }
        
        return dpt[0][a-1]%mod;
    }
    
public:
    int countWays(int n, string s){
        string x = "";
        string y = "";
        
        for(int i=0; i<n; i++){
            if(s[i] == 'T' || s[i] == 'F'){
                x += s[i];
            }else{
                y += s[i];
            }
        }
        
        int a = x.length();
        int b = y.length();
        
        return solve(x,y,a,b);
    }
};



// 3D DP wala solu GFG pe nhi chal rha 
// memset doesn't works on 3d dp

class Solution{
    
    // ll dp[205][205][2];
    // int dp[2][205][205];
    
    unordered_map<string,int> m;
    ll solve(string &s,int i,int j,bool isTrue){
        if(i > j){
            return 0;
        }
        if(i == j){
            if((isTrue && s[i] == 'T') || (!isTrue && s[i] == 'F')){
                return 1;
            }else{
                return 0;
            }
        }
        
        string temp = "";
        temp += to_string(i) + " " + to_string(j) + " " + to_string(isTrue);
        if(m.find(temp) != m.end()){
            return m[temp];
        }
        
        ll val = 0;
        for(int k=i+1; k<=j-1; k+=2){
            ll lt = solve(s,i,k-1,true); // left true
            ll lf = solve(s,i,k-1,false); // left false
            ll rt = solve(s,k+1,j,true); // right true
            ll rf = solve(s,k+1,j,false); // right false
            
            char ch = s[k];
            
            if(ch == '|'){
                if(isTrue){
                    val += ((lt*rt)%mod + (lt*rf)%mod + (lf*rt)%mod)%mod;
                }else{
                    val += ((lf*rf)%mod)%mod;
                }
            }else if(ch == '&'){
                if(isTrue){
                    val += ((lt*rt)%mod)%mod;
                }else{
                    val += ((lf*rf)%mod + (lt*rf)%mod + (lf*rt)%mod)%mod;
                }                
            }else if(ch == '^'){
                if(isTrue){
                    val += ((lt*rf)%mod + (lf*rt)%mod)%mod;
                }else{
                    val += ((lt*rt)%mod + (lf*rf)%mod)%mod;
                }                
            }
            
        }
        
        return m[temp] = val%mod;
    }
    
public:
    int countWays(int n, string s){
        ll solu = solve(s,0,n-1,true);
        
        
        return solu%mod;
    }
};