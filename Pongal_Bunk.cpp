#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
  cin>>n;
  vector<int> v(n+1,0);

  int q;
  cin>>q;

  while(q--){
    int l,r;
    cin>>l>>r;

    for(int i=l; i<=r; i++){
      v[i] += (i - l + 1);
    }

  }

  int m;
  cin>>m;
  for(int j=0; j<m; j++){
    int k;
    cin>>k;

    cout<<v[k]<<endl;
  }

	return 0;
}