#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl '\n'

ll fence(ll arr[], ll n, ll k){
  ll idx = 0;
  ll sum = 0;
  for(ll i=0; i<k; i++){
    sum += arr[i];
  }

  ll ans = sum;

  for(ll i=k; i<n; i++){
    sum = sum + arr[i] - arr[i-k];
    if(sum < ans){
      ans = sum;
      idx = i-k+1;
    }
  }

  return idx+1; // as it is taking 1 based indexing
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n,k;
  cin>>n>>k;

  ll arr[n];
  
  for(ll i=0; i<n; i++){
    cin>>arr[i];
  }

  cout<<fence(arr,n,k)<<endl;
	return 0;
}