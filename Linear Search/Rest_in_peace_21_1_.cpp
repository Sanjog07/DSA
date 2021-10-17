#include <bits/stdc++.h>
using namespace std;

string restInPeace(int n){
  if(n%21 == 0){
    return "The streak is broken!";
  }

  string str = to_string(n);
  int x = str.length();

  for(int i=0; i<x-1; i++){
    string s = str.substr(i,2); // from every i, and of length 2
    if(s == "21"){
      return "The streak is broken!";
    }
  }

  return "The streak lives still in our heart!";
}

int main(){
	int t;
  cin>>t;

  while(t--){
    int n;
    cin>>n;

    cout<<restInPeace(n)<<endl;
  }

	return 0;
}