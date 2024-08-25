
#define ll long long

// notebook


class Solution {
    
    bool solve(vector<int>& nums, ll cap, int d,ll n){
        ll sum = 0;
        ll i = 0;
        int days = 1;
        
        while(i < n){
            sum += nums[i];
            //i++;
            if(sum <= cap){
                i++;
            }else{
                sum = 0;
                days++;
            }
        }
        
        if(days <= d){
            return true;
        }
        
        return false;
    }
    
public:
    int shipWithinDays(vector<int>& nums, int d) {
        ll n = nums.size();
        
        ll s = *max_element(nums.begin(), nums.end());
        ll sum = 0;
        sum = accumulate(nums.begin(), nums.end(), sum);
        
        ll e = sum;
        
        ll ans = INT_MAX;
        while(s <= e){
            ll mid = (e - (e-s)/2);
            bool res = solve(nums, mid, d, n);
            if(res){
                ans = mid;
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        
        return ans;
    }
};



// bool canBeDone(vector<int>& weights, int days, int cap){
//     int n = weights.size();
    
//     int wei = 0;
//     int day = 1;
//     for(int i=0; i<n; i++){
//         wei += weights[i];
//         if(wei > cap){
//             day++;
//             if(day > days){
//                 return false;
//             }
//             i--;
//             wei = 0;
//         }
//     }
    
//     return true;
// }


// class Solution {
// public:
//     int shipWithinDays(vector<int>& weights, int days) {
//         // we'll take monotonic search space for capacity
//         // as hume capacity minimize krni hai
//         // so start and end max_ele and sum of array liya hai
//         // and fir jaisa aggressive cows wale ques mei
//         // approach lgate thhe vaisi approach lgayi hai
        
        
//         int n = weights.size();
        
//         //int s = *(max_element(weights.begin(). weights.end()));
//         int maxe = INT_MIN;
//         for(int i=0; i<n; i++){
//             maxe = max(maxe, weights[i]);
//         }
        
//         int s = maxe;
        
//         int sum = 0;
//         //sum = accumulate(weights.begin(). weights.end(), sum);
//         for(int i=0; i<n; i++){
//             sum += weights[i];
//         }
        
//         int e = sum;
//         int ans = INT_MAX;
//         while(s <= e){
//             int mid = (s+e) >> 1;
//             bool krSkteHai = canBeDone(weights, days, mid);
//             if(krSkteHai){
//                 ans = min(ans, mid);
//                 e = mid - 1;
//             }else{
//                 s = mid + 1;
//             }
//         }
        
//         return ans;
//     }
// };