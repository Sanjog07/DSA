

//    Ques and Solu ->   https://www.youtube.com/watch?v=OodoQ95se20

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl '\n'

ll solve(vector<ll> arr,ll n, ll k){
    vector<ll> kad(n,0);

    ll cs = 0;
    for(ll i=0; i<n; i++){
      cs += arr[i];
      kad[i] = cs;
      if(cs < 0){
        cs = 0;
      }
    }

    ll ans = INT_MIN;
    ll sum = 0;
    for(ll i=0; i<k; i++){
      sum += arr[i];
    }
    ans = max(ans, sum);

    for(ll i=k; i<n; i++){
      sum += (arr[i] - arr[i-k]); // window ko aage bdhayo
      ll x = kad[i-k];
      if(x > 0){
        ans = max(ans, (sum+x));
      }

      ans = max(ans, sum);
    }

    return ans;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n;
	cin>>n;
	vector<ll> v;
	for(int i=0; i<n; i++){
	    ll x;
	    cin>>x;
	    v.push_back(x);
	}
	
	ll k;
	cin>>k;
	
  cout<<solve(v,n,k)<<endl;

	return 0;
}