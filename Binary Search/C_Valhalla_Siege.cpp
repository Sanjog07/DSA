#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl '\n'



int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n,q;
	cin>>n>>q;

	ll arr[n];
	for(ll i=0; i<n; i++){
		cin>>arr[i];
	}

	ll nums[q];
	for(ll i=0; i<q; i++){
		cin>>nums[i];
	}

	ll pre[n]; // prefix array of arr
	pre[0] = arr[0];
	for(ll i=1; i<n; i++){
		pre[i] = pre[i-1] + arr[i];
	}

	// Solution
	ll arrows = 0;
	ll ans = -1;
	for(ll i=0; i<q; i++){
		arrows += nums[i];
		if(arrows >= pre[n-1]){
			// it means ki sabhi ke sabhi warriors marr jayege and vo firse zinda ho jayege
			ans = n;
			
			// i.e sb kuch almost firse start hoga
			arrows = 0;
		}else{
			ll x = upper_bound(pre, pre+n, arrows) - pre;
			ans = n-x;
		}
		cout<<ans<<endl;
	}

	return 0;
}