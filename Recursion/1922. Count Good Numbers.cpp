
long long mod = 1e9+7;

class Solution {
    
    long long power(long long a, long long b){
        if(b == 0){
            return 1;
        }
        
        long long smallPow = power(a,b/2);
        smallPow = ((smallPow%mod)*(smallPow%mod))%mod;
        
        if(b%2 == 0){
            return smallPow%mod;
        }
        
        return ((a%mod)*(smallPow%mod))%mod;
    }
    
public:
    int countGoodNumbers(long long n) {
        
        // as hume n length ki string bnani hai
        // and hmare pass 4 type ke prime no's hai
        // and 5 type ke even no's hai and hume inhi mei 
        // se select krne hai
        
        // so P&C lgayege -> even idx ke pass 5 opt hai
        // and odd idx ke pass 4 opt hai
        // e.g n=3, 5*4*5 = 100
        
        // so there will be total x = n/2 odd places and n-x even places
        
        long long ans = 1;
        long long x = n/2;
        // for(int i=0;i <x; i++){
        //     ans = ((ans%mod)*(4%mod))%mod;
        // }
        ans = ((ans % mod) * (power(4,x) % mod)) % mod;
        //ans = (ans * (long long)pow(4,x))%mod;
        long long y = n-x;
        // for(int i=0; i<y;  i++){
        //     ans = ((ans%mod)*(5%mod))%mod;
        // }
        ans = ((ans % mod) * (power(5,y) % mod)) % mod;
        //ans = (ans * (long long)pow(5,y))%mod;
        
        
        // long long ans = 1;
        // for(int i=0; i<n; i++){
        //     if(i%2 == 0){
        //         ans = (ans*5)%mod;
        //     }else{
        //         ans = (ans*4)%mod;
        //     }
        // }
        
        return ans%mod;
    }
};