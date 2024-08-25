#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl '\n'

ll fastPow(ll a, ll b){
  if(b == 0){
    return 1;
  }

  ll small = fastPow(a,b/2);
  small *= small;

  if(a%2 == 0){
    return small;
  }

  return a*small;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
  ll t;
  cin>>t;
  while(t--){
    ll t1,t2,r1,r2;
    cin>>t1>>t2>>r1>>r2;

    double a = fastPow(t1,2)/fastPow(r1,3);
    double b = fastPow(t2,2)/fastPow(r2,3);

    if(a == b){
      cout<<"Yes"<<endl;
    }else{
      cout<<"No"<<endl;
    }

  }

	return 0;
}