

//// https://leetcode.com/problems/count-the-hidden-sequences/discuss/1711078/C%2B%2B-or-O(N)-Easy-Solution-just-use-SIMPLE-MATH

///   refer above link -> phle link ko hi dekh lena


#define ll long long

class Solution {
public:
    int numberOfArrays(vector<int>& diff, int l, int u) {
        ll n = diff.size();
        
        // iss mei ek case ko acche se dekh lena when n==1;
        // usmei bhi jb vo element +ve ho and -ve ho
        // usmei niche wale logic ke saath saath x ki range
        // bhi check krni pdegi
        
        ll pre = 0;
        ll mx = 0;
        ll mi = 0;
        for(ll i=0; i<n; i++){
            pre += diff[i];
            
            mx = max(mx, pre);
            mi = min(mi, pre);
        }
        
        ll ans = ((u - mx) - (l - mi)); 
        if(ans < 0){
            return 0;
        }
        
        return ans+1;

    }
};