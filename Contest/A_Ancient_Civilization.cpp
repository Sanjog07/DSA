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
    ll n,l;
    cin>>n>>l;

    vector<ll> arr;
    for(ll i=0; i<n; i++){
      ll x;
      cin>>x;
      arr.push_back(x);
    }

    int ans = 0;
    int mask = 1;
    int i = 0;
    while(i < l){
      mask = (1 << i);
      int cnt = 0;
      for(int j=0; j<n; j++){
        int ele = arr[j];
        if(mask & ele){
          cnt++;
        }
      }
      if(cnt > n/2){
        ans += pow(2,i);
      }
      i++;
    }

    cout<<ans<<endl;
  }

	return 0;
}