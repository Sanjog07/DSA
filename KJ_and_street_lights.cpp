#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,p;
  cin>>n>>p;

  vector<int> v(p+1,0);
  for(int i=0; i<n; i++){
    int x,r;
    cin>>x>>r;

    int rx = (x-r);
    int ry = (x+r);

    int st = (rx < 0) ? 0 : rx;
    int end = (ry > p) ? p : ry;

    for(int j=st; j<=end; j++){
      if(v[j] == 1 || v[j] == -1){
        v[j] = -1;
      }else{
        v[j] = 1;
      }
    }

  }

  int cnt = 0;
  int ans = INT_MIN;

  for(int i=0; i<=p; i++){
    if(v[i] == 0 || v[i] == -1){
      cnt++;
    }else{
      ans = max(ans , cnt);
      cnt = 0;
    }
  }
  ans = max(ans , cnt);

  cout<<ans<<endl;

	return 0;
}