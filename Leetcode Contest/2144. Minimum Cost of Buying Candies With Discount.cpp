
// APNA SOLU -> neeche ek aur solu bhi hai
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        if(n == 1){
            return cost[0];
        }
        if(n == 2){
            return cost[0] + cost[1];
        }
        sort(cost.begin(), cost.end());
        
        int i=n-2,j=n-1;
        
        int ans = 0;
        while(i >= 0 && j >= 0){
            ans += cost[i] + cost[j];
            i = i-3;
            j = j-3;
        }
        while(j >= 0){
            ans += cost[j];
            j--;
        }
        
        return ans;
    }
};

// Bdiya wala

For the max value, we have to pay for it.
For the second max value, we still have to pay for it.
For the third max value, we can get it free one as bonus.
And continuely do this for the rest.

The the core of problem, is need to sort the input.
All A[i] with i % 3 == n % 3, we can get it for free.

int minimumCost(vector<int>& A) {
        sort(A.begin(), A.end());
        int res = 0, n = A.size();
        for (int i = 0; i < A.size(); ++i)
            if (i % 3 != n % 3) 
                res += A[i];
        return res;
    }
