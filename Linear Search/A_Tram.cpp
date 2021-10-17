#include <bits/stdc++.h>
using namespace std;

int minCapacity(vector<pair<int,int>> v, int n){
  int x = v[0].second;
  int cap = x;

  for(int i=1; i<n-1; i++){
    x -= v[i].first;
    x += v[i].second;

    cap = max(cap , x);
  }

  return cap;
}

int main(){
	int n;
  cin>>n;

  vector<pair<int,int>> v;
  for(int i=0; i<n; i++){
    int a,b;
    cin>>a>>b;
    v.push_back({a,b});
  }

  cout<<minCapacity(v,n)<<endl;

	return 0;
}