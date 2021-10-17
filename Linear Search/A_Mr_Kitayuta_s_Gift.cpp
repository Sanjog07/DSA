#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){
  string x = s;
  reverse(s.begin() , s.end());

  return s == x;
}

string solve(string s){
  int len = s.length();

  // i.e agr string pehle se hi palindrome hai tb usko palindrome bna skte hai
  if(isPalindrome(s)){
    if(len%2 == 0){
      s.insert(s.begin() + (len/2) , 'a'); // a ki jagah koi bhi character add lr skte hai koi farak nhi pdta
    }else{
      char ch = s[len/2];
      s.insert(s.begin() + (len/2) + 1 , ch);
    }
    return s;
  }else{
    for(int i=0; i<=len; i++){
      for(char ch='a'; ch <= 'z'; ch++){
        string str = s;  
        str.insert(str.begin() + i , ch);

        if(isPalindrome(str)){
          return str;
        }
      }
    }
  }

  return "NA";
}

int main(){
	string s;
  cin>>s;

  cout<<solve(s)<<endl;
	return 0;
}