#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl '\n'

bool rkhSkteHai(ll dist, ll c,ll n, ll arr[]){
	// kya hum dist, distance pe c cows ko rkh skte hai ya nhi
	// and we want to maximize the min dist

	ll prev = arr[0]; // position of prev cow
	ll cnt = 1; // no of cows placed, i.e first wali cow ko to first stall
	                                  // pe hi rkh do  

	for(ll i=1; i<n; i++){
		if((arr[i] - prev)  >= dist){                    
			cnt++;
			prev = arr[i];
			if(cnt == c){
				return true;
			}
		}
	}

	return false;
}

ll agrCows(ll c,ll n, ll arr[]){
	sort(arr, arr+n);

	ll s = 0;
	ll e = arr[n-1] - arr[0];
	ll ans = -1;

	while(s <= e){
		ll mid = (s+e)/2;
    //cout<<s<<" "<<e<<endl;
		bool canKeep = rkhSkteHai(mid,c,n,arr);
    //cout<<canKeep<<" ";
		if(canKeep){
			ans = mid;
			// then we'll try to increase it
			s = mid+1;
		}else{
			e = mid-1;
		}
	}

	return ans;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll t;
  cin>>t;
  while(t--){
    ll n,c;
    cin>>n>>c;

    ll arr[n];
    for(ll i=0; i<n; i++){
      cin>>arr[i];
    }

    cout<<agrCows(c,n,arr)<<endl;
  }

	return 0;
}