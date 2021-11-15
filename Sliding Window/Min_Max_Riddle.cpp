#include <bits/stdc++.h>
using namespace std;

#define ll long long int

//SOLUTION LINK: https://www.youtube.com/watch?v=CK8PIAF-m2E

//EXPLAINATION: 
//jyada nhi sochna simple hai -> ye current value kitne window size ka ans ho skti hai
// eg, arr = [10,20,30,50,10,70,30];
// min value of arr = 10
// so for 20 -> 20, 3 size ki array ka ans ho skti hai (na ki hai, but ho skti hai)
// i.e of [20,30,50] -> as iss arr ka min 20 hai
// and agr isse left ya right wali value i.e 10 ko include kre
// tb 20 ans nhi rhega

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  cout.tie(NULL);

	ll n;
  cin>>n;

  ll arr[n];
  for(ll i=0; i<n; i++){
    cin>>arr[i];
  }

  vector<ll> ans(n+1,0);

  vector<ll> nsr;
  vector<ll> nsl;

  stack<ll> s;
  s.push(n-1);

  nsr.push_back(n);
  for(ll i=n-2; i>=0; i--){
    while(!s.empty() && arr[s.top()] >= arr[i]){
      s.pop();
    }
    if(s.empty()){
      nsr.push_back(n);
    }else{
      nsr.push_back(s.top());
    }

    s.push(i);
  }

  reverse(nsr.begin(), nsr.end());

  stack<ll> st;
  st.push(0);

  nsl.push_back(-1);

  for(ll i=1; i<n; i++){
    while(!st.empty() && arr[st.top()] >= arr[i]){
      st.pop();
    }
    if(st.empty()){
      nsl.push_back(-1);
    }else{
      nsl.push_back(st.top());
    }

    st.push(i);    
  }

  // for(ll i=0; i<n; i++){
  //   cout<<nsr[i]<<"  "<<nsl[i]<<endl;
  // }

  ans[0] = 0;
  for(ll i=0; i<n; i++){
    ll x = nsr[i] - nsl[i] - 1;
    ans[x] = max(ans[x], arr[i]);
  }

  // for(ll i=1; i<=n; i++){
  //   cout<<ans[i]<<" ";
  // }

  for(ll i=n-1; i>=1; i--){
    ans[i] = max(ans[i], ans[i+1]);
  }

  for(ll i=1; i<=n; i++){
    cout<<ans[i]<<" ";
  }

	return 0;
}