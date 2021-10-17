#include <bits/stdc++.h>
using namespace std;

pair<char,int> maxOccurence(string s){
  int n = s.length();
  int freq[128]; // of size 128 -> bcz the last ASCII Value is 127
  memset(freq, 0, sizeof(freq));

  for(int i=0; i<n; i++){
    int x = int(s[i]); // ascii value of character at s[i]
    freq[x]++;
  }

  int max_ele = INT_MIN;
  int idx = 0;
  for(int i=0; i<128; i++){
    if(freq[i] > max_ele){
      max_ele = freq[i];
      idx = i;
    }
  }
  
  int p2 = freq[idx];
  char p1 = char(idx);

  return {p1, p2}; // and agr kinhi 2 ki freq same hai to automatically jiski ascii value same hai vo print hoga bcz of the if condi in the loop
}

int main(){
	string s;
  getline(cin , s);

  pair<char,int> ans = maxOccurence(s);
  cout<<ans.first<<" "<<ans.second<<endl;
	return 0;
}