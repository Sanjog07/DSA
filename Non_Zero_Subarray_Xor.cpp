#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl '\n'
 
// pre -> val      ptr -> x
ll solve(ll val, ll x){
  for(ll i=0; i<21; i++){
    if((x & (1<<i)) > 0){
      val ^= (1<<i);
    }
  }

  return val;
}

void helper(ll n){
  vector<ll> ans;
  map<ll,ll> m;

  m[0] = 1;
  ll x = 1, val = 0;

  for(ll i=0; i<n; i++){
    while(m[solve(val, x)] == 1){
      x++;
    }

    val = solve(val,x);
    m[val] = 1;
    ans.push_back(x);
    x++;
  }

  for(ll i=0; i<ans.size(); i++){
    cout<<ans[i]<<" ";
  }
  cout<<endl;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

  ll t;
  cin>>t;
  while(t--){
    ll n;
    cin>>n;

    helper(n);
  }
	

	return 0;
}