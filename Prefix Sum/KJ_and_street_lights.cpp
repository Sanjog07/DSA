#include <bits/stdc++.h>
using namespace std;

//  SOLUTION VIDEO : https://www.youtube.com/watch?v=uAAhD9rd3N8

// in this problem we're using Scanline Algo

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
    v[st] += 1; // i.e ye wala step scanline algo ka part hai

    // if((ry+1) <= p){
    //   v[ry+1] -= 1; // i.e ye wala step scanline algo ka part hai
    // }


    // line 28-36 ki jagha sirf line 23-25 bhi likh skte hai, that will also work but usse thodi clarity nhi aa rhi thi
    int end;
    if(ry <= p-1){
        end = ry;
    }else{
        end = p-1;
    }
      
    v[end+1] -= 1; // i.e ye wala step scanline algo ka part hai

    // for(int j=st; j<=end; j++){
    //   if(v[j] == 1 || v[j] == -1){
    //     v[j] = -1;
    //   }else{
    //     v[j] = 1;
    //   }
    // }

  }

  int cnt = 0;
  int ans = INT_MIN;

  vector<int> preSum(p+1);
  preSum[0] = v[0];
  int sum = v[0];
  for(int i=1; i<=p; i++){
    sum += v[i];
    preSum[i] = sum;
  }

  for(int i=0; i<=p; i++){
    if(preSum[i] == 0 || preSum[i] > 1){
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