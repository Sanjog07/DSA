#include <bits/stdc++.h>
using namespace std;

//SOLUTION LINK: https://www.youtube.com/watch?v=CvPIX0HBZbQ

int main(){
	int n;
  cin>>n;
  vector<int> a(n+1,0);

  int q;
  cin>>q;

  vector<int> pre(n+1,0);
  vector<int> arr(n+1,0);

  while(q--){
    int l,r;
    cin>>l>>r;

    // we'll use the scanline algo here
    // but here we'll not use the typical scanline algo 
    // but here we'll take prefix sum twice
    // and also will make 2 arrays 


    pre[l]++;
    if(r+1 < n+1){
      pre[r+1]--;

      arr[r+1] -= (r-l+1);
    }
  }

  //now take prefix arr of pre
  for(int i=2; i<=n; i++){
    pre[i] += pre[i-1];
  }

  // now again take prefix of pre but now with arr
  // i.e
  for(int i=2; i<=n; i++){
    pre[i] += pre[i-1] + arr[i];
  }

  int m;
  cin>>m;

  for(int j=0; j<m; j++){
    int k;
    cin>>k;

    cout<<pre[k]<<endl;
  }

	return 0;
}