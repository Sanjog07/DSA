#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl '\n'

ll solve(ll pro, ll mathe){
  ll x = pro + mathe;
  if(x < 4){
    return 0;
  }

  if(pro == mathe){
    return x/4;
  }

  ll expected = x/4;
  if(min(pro, mathe) >= expected){
    return x/4;
  }else{
    return min(pro, mathe);
  }
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
  ll t;
  cin>>t;
  while(t--){
    ll pro,mathe;
    cin>>pro>>mathe;

    cout<<solve(pro, mathe)<<endl;
  }
	return 0;
}