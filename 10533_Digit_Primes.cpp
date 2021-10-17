#include <bits/stdc++.h>
using namespace std;

#define ll long

ll isDigitPrime(ll n){
  // here n is definitely prime
  ll sum = 0;
  while(n > 0){
    sum += (n%10);
    n /= 10;
  }


  return sum;
}

ll max(int a, int b){
  if(a>b)
  return a;
  return b;
}

ll digitPrimesInRange(ll x,ll y,vector<ll> &v){
  //WE'LL USE PRIME SIEVE METHOD AS N IS LARGE

  //mark even no's as not prime
  for(ll i=4; i<=y; i+=2){
    v[i] = -1;
  }
  v[0] = v[1] = -1;
  // v[2] = 0;

    
  for(ll i=3; i<=y; i+=2){
    if(v[i] == 0){
      // so mark all the multiples of this no as not prime
      for(ll j=i*i; j<=y; j+=i){
        v[j] = -1;
      }
    }
  }

// && j%2 != 0

  // for(ll i=3; i<=y; i+=2){
  //   v[i] = 1;
  // }
  
  // for(ll i=3; i<=y; i+=2){
  //   if(v[i] == 1){
  //     // so mark all the multiples of this no as not prime
  //     for(ll j=i*i; j<=y; j+=i){
  //       v[j] = 0;
  //     }
  //   }
  // }

  // v[0] = v[1] = 0;
  // v[2] = 1;

  // for(ll i=x; i<=y; i++){
  //   cout<<v[i]<<" ";
  // }
  // cout<<endl;

  ll cnt = 0;
  for(ll i=x; i<=y; i++){
    if(v[i] == 0){
      int sum = isDigitPrime(i);
      if(v[sum] == 0){
          cnt++;
      }
    }
  }

  return cnt;
}


int main(){

  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);

	ll t;
  // cin>>t;
  scanf("%ld" , &t);

  while(t--){
    ll x,y;
    // cin>>x>>y;
    scanf("%ld" , &x);
    scanf("%ld" , &y);

    vector<ll> v(y+1, 0);
    // cout<<digitPrimesInRange(x,y)<<endl;
    ll ans = digitPrimesInRange(x,y,v);
    printf("%ld\n" , ans);

    // for(int i=0; i<=y; i++){
    //   cout<<v[i]<<" ";
    // }
    // cout<<endl;
  }

	return 0;
}