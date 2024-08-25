#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl '\n'

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

  ll t;
  cin>>t;
  while(t--){
    ll n,x;
    cin>>n>>x;
    string s;
    cin>>s;

    vector<ll> v;

    ll zero = 0;
    ll one = 0;
    for(ll i=0; i<n; i++){
      if(s[i] == '0'){
        zero++;
      }else{
        one++;
      }
    }

    if(zero == n || zero == n-1){
      cout<<n/x<<endl;
      continue;
    }
    if(one == n){
      if(x == 1){
        cout<<1<<endl;
      }else if(x > 1){
        cout<<0<<endl;
      }

      continue;
    }

    ll cnt = 0;
    for(ll i=0; i<n; i++){
      char ch = s[i];
      if(ch == '1'){
        v.push_back(cnt);
        cnt = 0;
      }else{
        cnt++;
      }
    }

    ll sz = v.size();
    if(cnt > 0){
      v[sz-1] += cnt;
    }

    ll ans = INT_MIN;
    for(ll i=1; i<sz; i++){
      ll val = v[i] + v[i-1];
      ans = max(ans, val);
    }

    ans += 1;
  
    ll solu = ans/x;

    cout<<solu<<endl;

  }
	

	return 0;
}