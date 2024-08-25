#include <iostream>
using namespace std;
int DecimaltoBinary(int n){
    int ans = 0; 
    int power = 1;
    while(n>0){
        int last_bit = (n&1);
        ans = ans + (power*last_bit);
        n = (n>>1);
        power = power*10;
    }
    return ans;
}
int main() {
    int n;
    cin>>n;
    cout<<DecimaltoBinary(n);
    return 0;
}
