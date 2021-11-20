class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& arr, int k) {
//         int n = arr.size();
//         int cnt = 0;
        
//         deque<int> q;
//         if(arr[0] < k){
//             cnt++;
//             q.push_back(arr[0]);
//         }
        
//         for(int i=1; i<n; i++){
//             if(arr[i] < k){
//                 cnt++;
//             }
            
//             queue<int> qu;
//             while(!q.empty()){
//                 int p = q.front()*arr[i];
//                 if(p < k){
//                     cnt++;
//                     qu.push(p);
//                 }
//                 q.pop_front();
//             }
            
//             q.push_back(arr[i]);
            
//             while(!qu.empty()){
//                 q.push_back(qu.front());
//                 qu.pop();
//             }
//         }
        
//         return cnt;
    
            
        //
        
        // Variable size window wale ques mei, l and r le liya kro
        // and fir ques ke hisaab se logic likho
    // and r-l+1 -> ans ho skta hai (fir dekh lena given condi ke hisaab se)
        
        int n = arr.size();
        int cnt = 0;
        
        // here all the elements are +ve
        long long int pro = 1;
        int l=0, r=0;
        
        while(l <= r && r < n){
            pro *= arr[r];
            
            if(pro < k){
                cnt += (r-l+1);
            }else{
                while(pro >= k && l <= r){
                    pro /= arr[l];
                    l++;
                }
                
                if(l <= r){
                    cnt += (r-l+1);
                }
            }
            
            r++;
        }
        
        return cnt;
    }
};