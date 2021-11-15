#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl '\n'

int solve(ll arr[], ll n){
    map<ll, ll, greater<ll> >m;
    //bool flag = false;
    for(ll i=0; i<n; i++){
      m[arr[i]]++;
    }

    // bool out = false;
    // if(flag){
    //   cout<<-1<<endl;
    //   out = true;
    // }

    // sort(arr,arr+n,greater<int>());
    // if(m[arr[0]] == 2){
    //   cout<<-1<<endl;
    //   out = true;
    // }
    auto it = m.begin();
    if(it->second == 2){
      // cout<<-1<<endl;
      // out = true;
      return -1;
    }

    for(auto x: m){
      if(x.second > 2){
        // flag = true;
        // break;
        return -1;
      }
    }

    //sort(arr,arr+n);
    //ll x = INT_MAX; // kuch bhi value le skte hai
    //if(!out){
      // for(ll i=0; i<n; i++){
      //   if(m[arr[i]] == 2 && arr[i] != x){ // ye arr[i] != x isliye likha hai -> ye check krne ke liye taaki ek value baar baar print na ho
      //     cout<<arr[i]<<" ";
      //     x = arr[i];
      //   }
      // }

      // iterate over map in reverse order
      // ye cheez array ki sort krke bhi kr skte hai but it'll take NLOGN
      for(auto it=m.rbegin(); it!=m.rend(); it++){
        if(it->second == 2){
          cout<<it->first<<" ";
        }
      }

      for(auto y: m){
        cout<<y.first<<" ";
      }
      cout<<endl;
    //}    

    return 0;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  cout.tie(NULL);

	ll t;
	cin>>t;

  while(t--){
  	ll n;
    cin>>n;
    ll arr[n];
    map<ll, ll, greater<ll> >m;
    for(ll i=0; i<n; i++){
      cin>>arr[i];
    }
    // map<ll, ll, greater<ll> >m;
    // bool flag = false;
    // for(ll i=0; i<n; i++){
    //   cin>>arr[i];
    //   m[arr[i]]++;

    //   if(m[arr[i]] > 2){
    //     flag = true;
    //     break;
    //   }
    // }

    // bool out = false;
    // if(flag){
    //   cout<<-1<<endl;
    //   out = true;
    // }

    // // sort(arr,arr+n,greater<int>());
    // // if(m[arr[0]] == 2){
    // //   cout<<-1<<endl;
    // //   out = true;
    // // }
    // auto it = m.begin();
    // if(it->second == 2){
    //   cout<<-1<<endl;
    //   out = true;
    // }

    // //sort(arr,arr+n);
    // //ll x = INT_MAX; // kuch bhi value le skte hai
    // if(!out){
    //   // for(ll i=0; i<n; i++){
    //   //   if(m[arr[i]] == 2 && arr[i] != x){ // ye arr[i] != x isliye likha hai -> ye check krne ke liye taaki ek value baar baar print na ho
    //   //     cout<<arr[i]<<" ";
    //   //     x = arr[i];
    //   //   }
    //   // }

    //   // iterate over map in reverse order
    //   // ye cheez array ki sort krke bhi kr skte hai but it'll take NLOGN
    //   for(auto it=m.rbegin(); it!=m.rend(); it++){
    //     if(it->second == 2){
    //       cout<<it->first<<" ";
    //     }
    //   }

    //   for(auto y: m){
    //     cout<<y.first<<" ";
    //   }
    //   cout<<endl;
    // }  

    int ans = solve(arr,n);
    if(ans == -1){
      cout<<ans<<endl;
    }
  }

	return 0;
}