
#define ll long long

class Solution{
  
  bool solve(int arr[], int n, int k,ll mid){
      ll cnt = 1;
      
      ll sum = 0;
      for(int i=0; i<n; i++){
          sum += arr[i];
          if(sum > mid){
              cnt++;
              if(cnt > k){
                  return false;
              }
              sum = arr[i];
          }
      }
      
      return true;
  }
  
  public:
    long long minTime(int arr[], int n, int k){
        
        ll s = *max_element(arr, arr+n);
        
        ll sum = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
        }
        
        ll e = sum;
        
        ll ans = 0;
        while(s <= e){
            ll mid = s + (e-s)/2;
            bool res = solve(arr, n, k, mid);
            if(res){
                ans = mid;
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }
        
        return ans;
    }
};