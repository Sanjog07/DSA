#include <bits/stdc++.h>
using namespace std;

int decimalToBinary(int no){
  int i = 0 , x = 0;

  while(no){
    int y = no%2; 
    x += (y * pow(10 , i));
    i++; 
  }

  return x;
}

int main(){
  int no1 , no2;
  cin>>no1>>no2;

  int ans = no1^no2;

  cout<<decimalToBinary(ans)<<endl;

	return 0;
}
