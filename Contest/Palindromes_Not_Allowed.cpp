#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl '\n'

string str = "abcdefghijklmnopqrstuvwxyz";
string solve(int n){
  string ans = "";
  if(n <= 26){
    ans = str.substr(0,n);
  }else{
    ll x = n/26;
    ll y = (n-x*26);

    for(int i=0; i<x; i++){
      ans += str;
    }

    if(y > 0){
      ans += str.substr(0,y);
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
     ll n;
     cin>>n;

     cout<<solve(n)<<endl;
   }

	return 0;
}