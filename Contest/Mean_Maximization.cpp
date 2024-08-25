#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl '\n'

void solve(vector<ll> arr, ll n){
  double sum = 0;
  for(ll i=0; i<n-1; i++){
    sum += arr[i];
  }

  sum /= (n-1);

  double ans = (sum+arr[n-1]);

  cout<<fixed<<setprecision(6)<<ans<<endl;
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

    vector<ll> arr;
    for(ll i=0; i<n; i++){
      ll x;
      cin>>x;
      arr.push_back(x);
    }
  
    sort(arr.begin(), arr.end());

    solve(arr,n);

  }

	return 0;
}