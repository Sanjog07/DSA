ll fastPow(ll a,ll b){
    if(b == 0){
        return 1;
    }
    
    ll smallPow = fastPow(a,b/2);
    smallPow *= smallPow;
    
    if(b%2 == 0){
        return smallPow;
    }
    return a*smallPow;
}