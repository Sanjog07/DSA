
#define ll long long
#define mod 1337

//SOLUTION LINK: https://leetcode.com/problems/super-pow/discuss/1613940/C%2B%2B-beats-100

class Solution {
    
    ll power(ll a, ll b){
        if(b == 0){
            return 1;
        }
        
        ll smallPow = power(a,b/2);
        smallPow = ((smallPow%mod)*(smallPow%mod))%mod;
        
        if(b%2 == 0){
            return smallPow%mod;
        }
        
        return ((a%mod)*(smallPow%mod))%mod;
    }
    
public:
    int superPow(int a, vector<int>& b) {
        if(a == 1){
            return 1;
        }
        
        int n = b.size();
        
        //int x = a%mod;
        int ans = 1 , p = 1, r = 0;
        for(int i=n-1; i>=0; i--){
            // r = (b[i] * power(10,p));
            // ans = ((ans)*(power(a,r)))%mod;
            // p++;
            
            
            
            // r = (b[i]*(p%mod))%mod;
            // ans = ((ans)*(power(a,r)))%mod;
            // p = ((p%mod)*10)%mod;
        }
        
        return ans;
    }
};