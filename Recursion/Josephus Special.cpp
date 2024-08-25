
// SOLUTION LINK: https://www.youtube.com/watch?v=NjcMT9wZHV0

#include<bits/stdc++.h>
using namespace std;

int main() {

  int n;
  cin >> n;

  // this problem is a special case of josephus problem with k = 2

  if (n == 1) {
    return 1;
  }

  // represent n in the form of 2^x + l
  // and the ans will be 2l+1

  int p = 1;
  while (p * 2 <= n) {
    p *= 2;
  }

  int l = (n - p);

  int ans = (2*l + 1);
  cout << ans << endl;

  return 0;
}