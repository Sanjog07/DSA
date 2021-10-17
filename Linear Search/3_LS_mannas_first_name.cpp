#include <bits/stdc++.h>
using namespace std;

///////// QUESTION LINK ////////////
//https://www.easycodingzone.com/2021/04/mannas-first-name.html
 
pair<int,int> mannaFirstName(string s){
  string str = "suvojit";
  int i=0, j=0;
  int a=0; // freq of "suvo"
  int b=0; // freq of "suvojit"

  int n = s.length();
  int m = str.length();

  string x = "";
  int cnt = 0;
  while(i<n && j<m && cnt < n){
    if(s[i] == str[j]){
      cnt++;

      x += s[i];
      if(x == "suvo"){
        a++;
      }else if(x == "suvojit"){
        b++;
      }

      i++;
      j++;
    }else{
      cnt++;

      x = "";
      j = 0;
    }
  }

  a -= b;

  return {a,b};
}

int main(){
	string s;
  cin>>s;

  pair<int,int> p = mannaFirstName(s);
  cout<<p.first<<" "<<p.second<<endl;

	return 0;
}