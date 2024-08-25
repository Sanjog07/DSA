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
    ll n,k,x;
    cin>>n>>k>>x;

    vector<ll> ans(n,-1);
    if(x > k){
      cout<<-1<<endl;
    }else{
      ll i = 0;
      ll a = 0;
      while(i < k){
        ans[i] = a;
        a = (a+1)%x;
        i++;
      }

      for(ll i=k; i<n; i++){
        ans[i] = ans[i-k];
      }


      for(ll i=0; i<n; i++){
        cout<<ans[i]<<" ";
      }
      cout<<endl;      
    }
    
  }
	

	return 0;
}