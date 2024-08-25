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
    ll x,y,z;
    cin>>x>>y>>z;

    if(x >= y){
      cout<<"PIZZA"<<endl;
    }else if(x >= z && x < y){
      cout<<"BURGER"<<endl;
    }else{
      cout<<"NOTHING"<<endl;
    }     
  }

	return 0;
}