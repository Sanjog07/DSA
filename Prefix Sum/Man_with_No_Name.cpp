#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(ll n, vector<ll> &v){
  ll sum = 0;
  for(ll i=0; i<n; i++){
    if(v[i] != -1){
      sum += v[i];
    }else if(i != 0){
      ll val = floor(sum/i);
      v[i] = val;
      sum += val;
    }else{
      v[i] = 0;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

	ll t;
  cin>>t;
  // vector<ll> v;

  while(t--){
    ll n;
    cin>>n;

    vector<ll> v;
    for(ll i=0; i<n; i++){
      ll x;
      cin>>x;
      v.push_back(x);
    }

    solve(n,v);

    for(ll i=0; i<n; i++){
      cout<<v[i]<<" ";
    }
    cout<<endl;

    // v.clear();
  }

	return 0;
}