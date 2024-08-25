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
    ll x,y,z;
    cin>>x>>y>>z;

    ll ans = x*(z-y);

    cout<<ans<<endl;
  }
	

	return 0;
}