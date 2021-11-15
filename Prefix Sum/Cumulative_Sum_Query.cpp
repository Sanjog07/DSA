#include <bits/stdc++.h>
using namespace std;

int sumInRange(int pre[], int n,int i,int j){
  int sum = 0;
  if(i == 0){
    sum = pre[j];
  }else{
    sum = (pre[j] - pre[i-1]);
  }

  return sum;
}

int main(){
	int n;
  cin>>n;

  int arr[n];
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }

  int pre[n];
  pre[0] = arr[0];

  for(int i=1; i<n; i++){
    pre[i] = pre[i-1] + arr[i];
  }

  int q;
  cin>>q;
  while(q--){
    int i,j;
    cin>>i>>j;

    cout<<sumInRange(pre,n,i,j)<<endl;
  }
	return 0;
}