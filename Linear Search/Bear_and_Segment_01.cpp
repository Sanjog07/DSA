#include <bits/stdc++.h>
using namespace std;

int helper(string str,int n){
  for(int i=0; i<n; i++){
    if(str[i] == '1'){
      return i;
    }
  }
}

string bearAndSegment(string s){
  int n = s.length();
  int freq = 0; // freq of 1's

  for(int i=0; i<n; i++){
    if(s[i] == '1'){
      freq++;
    }
  }

  if(freq == 0){
    return "NO";
  }

  int x = helper(s,n); // '1' string mei first time kis idx pe aaya
  string b = s;
  reverse(b.begin(), b.end());
  int a = helper(b, n);
  int y = n-1-a; // '1' string mei last time kis idx pe aaya

  if((y - x + 1) == freq){
    return "YES";
  }

  return "NO";
}

int main(){
	int t;
  cin>>t;
  while(t--){
    string s;
    cin>>s;

    cout<<bearAndSegment(s)<<endl;
  }

	return 0;
}