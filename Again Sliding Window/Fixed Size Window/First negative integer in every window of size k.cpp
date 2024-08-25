#define ll long long

vector<ll> printFirstNegativeInteger(ll nums[],ll n, ll k) {
    vector<ll> ans;
    deque<ll> dq;
    for(ll i=0; i<k; i++){
        if(nums[i] < 0){
            dq.push_back(i);
        }
    }   

    if(!dq.empty()){
        ans.push_back(nums[dq.front()]);
    }else{
        ans.push_back(0); 
    }                   
    
    for(ll i=k; i<n; i++){
        if(nums[i] < 0){
            dq.push_back(i);
        }

        if(!dq.empty()){
            // out of bound
            ll idx = dq.front();
            if((i-idx+1) > k){
                dq.pop_front();
            }
            
            if(!dq.empty()){
                ans.push_back(nums[dq.front()]);   
            }else{
                ans.push_back(0);   
            }            
        }else{
            ans.push_back(0);   
        }
    }       

    return ans;     
}