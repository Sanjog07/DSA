// The API isBadVersion is defined for you.
// bool isBadVersion(int version);


// https://leetcode.com/problems/first-bad-version/discuss/1878120/c%2B%2B-fastest-solution-or-Binary-search

class Solution {
public:
    int firstBadVersion(int n) {
        int s = 1;
        int e = n;
        
        //long long int pvt = -1;
        while(s <= e){
            long long int mid = s + (e-s)/2;
            if(isBadVersion(mid)){
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        
        return s;
    }
};