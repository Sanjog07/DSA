#include <bits/stdc++.h>
using namespace std;

#define ll long long int

pair<ll,ll> maxSumSubset(ll arr[],ll n){
  ll cnt = 0;
  ll sum = 0;


  ll neg = 0;

  for(ll i=0; i<n; i++){
    if(arr[i] < 0){
      neg++;
    }
  }
  if(neg == n){
    ll x = *(max_element(arr,arr+n));
    return {x , 1};
  }

  for(ll i=0; i<n; i++){
    if(arr[i] >= 0){
      sum += arr[i];
      cnt++;
    }
  }

  return {sum , cnt};
}

int main(){
	ll n;
  cin>>n;
  ll arr[n];
  for(ll i=0; i<n; i++){
    cin>>arr[i];
  }

  pair<ll,ll> ans = maxSumSubset(arr,n);
  cout<<ans.first<<" "<<ans.second<<endl;

	return 0;
}