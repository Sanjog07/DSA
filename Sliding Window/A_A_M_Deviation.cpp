#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl '\n'

ll solve(ll a, ll b, ll c){
  // ll ans;

  // ll x = (a+c) - 2*b;
  // if(x == 0){
  //   return 0;
  // }

  // while(true){
  //   if(x < 0){
  //   // i.e b ko chhota krna pdega
  //   b--;
  //   if(a > c){
  //     a++;
  //   }else{
  //     c++;
  //   }
  //   ans = (a+c) - 2*b;
  //   if(ans == 0){
  //     return 0;
  //   }
  //   //solu = min(ans,solu);
  //   }else{
  //     b++;

  //     if(a < c){
  //       a--;
  //     }else{
  //       c--;
  //     }
  //     ans = (a+c) - 2*b;
  //     if(ans == 0){
  //       return 0;
  //     }
  //     //solu = min(ans,solu);
  //   }

  //   if(x > 0 && ans < 0){
  //     return min(x, -1*ans);
  //   }else if(x < 0 && ans > 0){
  //     return min(-1*x, ans);
  //   }  

  //   x = ans;
  // }

  double ans = double((a+c) - 2*b)/double(3);

  if(floor(ans) == ceil(ans)){
    return 0;
  }else{
    return 1;
  }

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

  ll t;
  cin>>t;
  while(t--){
    ll a,b,c;
    cin>>a>>b>>c;

    cout<<solve(a,b,c)<<endl;
  }

	return 0;
}