#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl '\n'

// bool canMidBeAns(ll arr[], ll n, ll k,, ll mid){
//   // agr mid ans hai to abhi tk humne mid no of times 
//   // elements mei se -1 subtract kiya hoga


// }

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
  ll n,k;
  cin>>n>>k;

  ll arr[n];
  ll sum = 0;
  for(ll i=0; i<n; i++){
    //cin>>arr[i];
    ll x;
    cin>>x;

    sum += x;
  }

  ll ans = sum/k;

  cout<<ans<<endl;

  // //O(n^2) SOLUTION USING PRIORITY QUEUES

  // priority_queue<ll> pq;
  // for(ll i=0; i<n; i++){
  //   ll x;
  //   cin>>x;
  //   pq.push(x);
  // }

  // ll time = 0;
  // while(pq.size() >= k){
  //   for(ll i=0; i<k; i++){
  //     ll a = pq.top();
  //     pq.pop();

  //     if(a > 1){
  //       pq.push(a-1);
  //     }
  //   }
  //   time++;
  // }
  // cout<<time<<endl;

  // // SO TO OPTIMIZE WE'LL APPLY BINARY SEARCH
  // ll s = 0;
  // ll e = n*1e9 + 1;

  // ll time = -1;
  // while(s <= e){
  //   ll mid = (s+e) >> 1;

  //   // so we'll check that -> can mid be the answer
  //   bool check = canMidBeAns();
  //   if(check){
  //     time = mid;
  //     s = mid + 1;
  //   }else{
  //     e = mid - 1;
  //   }
  // }

  // cout<<time<<endl;

	return 0;
}