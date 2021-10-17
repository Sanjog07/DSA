#include <bits/stdc++.h>
using namespace std;

int solve(int arr[],int n){
  int odd = 0 , even = 0;

  for(int i=0; i<n; i++){
    if(arr[i] % 2 == 0){
      even++;
    }else{
      odd++;      
    }
  }

  if(even == 1){
    for(int i=0; i<n; i++){
      if(arr[i]%2 == 0){
        return i+1;
      }
    }
  }else if(odd == 1){
    for(int i=0; i<n; i++){
      if(arr[i]%2 != 0){
        return i+1;
      }
    }    
  }
  
}

int main(){
  int n;
  cin>>n;
  int arr[101];
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }

  cout<<solve(arr,n)<<endl;

	return 0;
}