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
    ll n;
    cin>>n;

    ll x = 2;
    for(ll i=0; i<n; i++){
      cout<<x<<" ";
      if(i&1){
        x += 3;
      }else{
        x++;
      }
    }
    cout<<endl;

  }
	return 0;
}