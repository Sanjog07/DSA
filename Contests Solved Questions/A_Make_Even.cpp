#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl '\n'

ll solve(ll n){
    if(n%2 == 0){
      return 0;
    }

    vector<int> v;
    ll odd = 0;
    while(n > 0){
      int x = n%10;
      if(x%2 != 0){
        odd++;
      }
      v.push_back(x);
      n = n/10;
    }

    int a = v.size();
    if(odd == a){
      return -1;
    }

    if(v[a-1]%2 == 0){
      return 1;
    }

    return 2;
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

    cout<<solve(n)<<endl;

  }

	return 0;
}